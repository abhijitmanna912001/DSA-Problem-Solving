#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int getMinValueNode(vector<int> &key, vector<int> &mst)
    {
        int temp = INT_MAX;
        int idx = -1;

        for (int i = 0; i < key.size(); i++)
        {
            if (key[i] < temp && mst[i] == false)
            {
                temp = key[i];
                idx = i;
            }
        }
        return idx;
    }

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> key(V, INT_MAX);
        vector<int> mst(V, false);
        vector<int> parent(V, -1);

        key[0] = 0;

        while (true)
        {
            int u = getMinValueNode(key, mst);
            if (u == -1)
                break;

            mst[u] = true;
            for (auto edge : adj[u])
            {
                int v = edge[0];
                int w = edge[1];
                if (mst[v] == false && w < key[v])
                {
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }

        int sum = 0;
        for (int u = 0; u < parent.size(); u++)
        {
            if (parent[u] == -1)
                continue;
            for (auto edge : adj[u])
            {
                int v = edge[0];
                int w = edge[1];
                if (v == parent[u])
                    sum += w;
            }
        }
        return sum;
    }
};

int main()
{

    return 0;
}