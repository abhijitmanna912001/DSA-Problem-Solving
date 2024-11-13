#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool checkCyclic(int src, unordered_map<int, bool> &vis, unordered_map<int, bool> &dfsTrack, vector<int> adj[])
    {
        vis[src] = true;
        dfsTrack[src] = true;

        for (auto nbr : adj[src])
        {
            if (!vis[nbr])
            {
                bool ans = checkCyclic(nbr, vis, dfsTrack, adj);
                if (ans == true)
                    return true;
            }

            if (vis[nbr] == 1 && dfsTrack[nbr] == 1)
                return true;
        }

        dfsTrack[src] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        unordered_map<int, bool> vis;
        unordered_map<int, bool> dfsTrack;

        for (int node = 0; node < V; node++)
        {
            if (!vis[node])
            {
                bool isCycle = checkCyclic(node, vis, dfsTrack, adj);
                if (isCycle)
                    return true;
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}