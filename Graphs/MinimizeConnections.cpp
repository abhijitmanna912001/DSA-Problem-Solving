#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findParent(vector<int> &parent, int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent, parent[node]);
    }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        u = findParent(parent, u);
        v = findParent(parent, v);

        if (rank[u] < rank[v])
        {
            parent[u] = v;
            rank[v]++;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        int noOfExtraEdges = 0;
        for (auto connection : connections)
        {
            int u = connection[0];
            int v = connection[1];

            u = findParent(parent, u);
            v = findParent(parent, v);

            if (u != v)
                unionSet(u, v, parent, rank);
            else
                noOfExtraEdges++;
        }

        int nocc = 0;
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
                nocc++;
        }
        int ans = nocc - 1;
        return noOfExtraEdges >= ans ? ans : -1;
    }
};

int main()
{

    return 0;
}