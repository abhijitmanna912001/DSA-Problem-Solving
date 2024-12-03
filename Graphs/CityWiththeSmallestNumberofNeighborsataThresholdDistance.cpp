#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <list>
using namespace std;

class Solution
{
public:
    int dijkstraShortestDist(int src, int n, unordered_map<int, list<pair<int, int>>> &adj, int &distanceThreshold)
    {
        vector<int> dist(n + 1, INT_MAX);
        set<pair<int, int>> st;

        dist[src] = 0;
        st.insert({0, src});
        int reachableCities = 0;

        while (!st.empty())
        {
            auto top = *st.begin();
            st.erase(st.begin());
            int nodeDist = top.first;
            int node = top.second;

            if (node != src && nodeDist <= distanceThreshold)
                reachableCities++;

            for (auto nbr : adj[node])
            {
                int currDist = nodeDist + nbr.second;
                if (currDist < dist[nbr.first])
                {
                    auto it = st.find({dist[nbr.first], nbr.first});
                    if (it != st.end())
                        st.erase(it);

                    dist[nbr.first] = currDist;
                    st.insert({dist[nbr.first], nbr.first});
                }
            }
        }
        return reachableCities;
    }
    
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto edge : edges)
        {
            int &u = edge[0];
            int &v = edge[1];
            int &w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int city = 0;
        int minReachableCities = INT_MAX;
        for (int u = 0; u < n; u++)
        {
            int reachableCitiesCount = dijkstraShortestDist(u, n, adj, distanceThreshold);
            if (reachableCitiesCount <= minReachableCities)
            {
                minReachableCities = reachableCitiesCount;
                city = u;
            }
        }
        return city;
    }
};

int main()
{

    return 0;
}