#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

class Solution
{
public:
    // M2 - More Optimisation
    void dfs(int node, int parent, vector<int> &disc, vector<int> &low,
             vector<vector<int>> &result, vector<vector<int>> &adj, int &time)
    {
        disc[node] = low[node] = ++time;

        for (int neighbor : adj[node])
        {
            if (neighbor == parent)
                continue;
            if (disc[neighbor] == -1)
            {
                dfs(neighbor, node, disc, low, result, adj, time);
                low[node] = min(low[node], low[neighbor]);
                if (low[neighbor] > disc[node])
                {
                    result.push_back({node, neighbor});
                }
            }
            else
            {
                low[node] = min(low[node], disc[neighbor]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n);
        for (auto &conn : connections)
        {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }

        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        vector<vector<int>> result;
        int time = 0;

        dfs(0, -1, disc, low, result, adj, time);

        return result;
    }

    // M1- Tarjan's Algorithm
    void solve(int src, int parent, unordered_map<int, list<int>> &adj, int timer, vector<vector<int>> &ans, vector<int> &tin, vector<int> &low, unordered_map<int, bool> &vis)
    {
        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        for (auto nbr : adj[src])
        {
            if (nbr == parent)
                continue;

            if (!vis[nbr])
            {
                solve(nbr, src, adj, timer, ans, tin, low, vis);
                low[src] = min(low[src], low[nbr]);
                if (low[nbr] > tin[src])
                {
                    vector<int> temp;
                    temp.push_back(src);
                    temp.push_back(nbr);
                    ans.push_back(temp);
                }
            }
            else
                low[src] = min(low[src], low[nbr]);
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        unordered_map<int, list<int>> adj;
        for (auto vec : connections)
        {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int timer = 1;
        vector<vector<int>> ans;
        vector<int> low(n, 0);
        vector<int> tin(n, 0);

        int src = 0, parent = -1;
        unordered_map<int, bool> vis;
        solve(src, parent, adj, timer, ans, tin, low, vis);
        return ans;
    }
};

int main()
{

    return 0;
}