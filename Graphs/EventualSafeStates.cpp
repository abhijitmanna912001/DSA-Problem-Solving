#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool checkCyclic(int src, unordered_map<int, bool> &vis, unordered_map<int, bool> &dfsTrack, vector<int> adj[], int safeNodes[])
    {
        vis[src] = true;
        dfsTrack[src] = true;
        safeNodes[src] = 0;

        for (auto nbr : adj[src])
        {
            if (!vis[nbr])
            {
                bool ans = checkCyclic(nbr, vis, dfsTrack, adj, safeNodes);
                if (ans == true)
                    return true;
            }

            if (vis[nbr] == 1 && dfsTrack[nbr] == 1)
                return true;
        }

        dfsTrack[src] = false;
        safeNodes[src] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> ans;
        unordered_map<int, bool> vis, dfsTrack;
        int safeNodes[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                checkCyclic(i, vis, dfsTrack, adj, safeNodes);
        }

        for (int i = 0; i < V; i++)
            if (safeNodes[i])
                ans.push_back(i);
        return ans;
    }
};

int main()
{

    return 0;
}