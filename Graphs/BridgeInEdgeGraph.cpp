#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(int node, int parent, vector<int> &disc, vector<int> &low, vector<int> adj[], int &time, bool &isBridgeEdge, int c, int d)
    {
        disc[node] = low[node] = ++time;

        for (int neighbor : adj[node])
        {
            if (neighbor == parent)
                continue;

            if (disc[neighbor] == -1)
            {
                dfs(neighbor, node, disc, low, adj, time, isBridgeEdge, c, d);
                low[node] = min(low[node], low[neighbor]);

                if (low[neighbor] > disc[node] && ((node == c && neighbor == d) || (node == d && neighbor == c)))
                    isBridgeEdge = true;
            }
            else
                low[node] = min(low[node], disc[neighbor]);
        }
    }

    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        int time = 0;
        bool isBridgeEdge = false;

        for (int i = 0; i < V; ++i)
        {
            if (disc[i] == -1)
                dfs(i, -1, disc, low, adj, time, isBridgeEdge, c, d);
        }

        return isBridgeEdge ? 1 : 0;
    }
};

int main()
{

    return 0;
}