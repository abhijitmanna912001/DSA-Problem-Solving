#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <set>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int wt, bool direction)
    {
        if (direction == 1)
            adj[u].push_back({v, wt});
        else
        {
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
    }

    void dijkstraShortestDist(int n, int src, int dest)
    {
        vector<int> dist(n + 1, INT_MAX);
        set<pair<int, int>> st;

        dist[src] = 0;
        st.insert({0, src});

        while (!st.empty())
        {
            auto topElement = st.begin();
            pair<int, int> topPair = *topElement;
            int topDist = topPair.first;
            int topNode = topPair.second;
            st.erase(st.begin());

            for (pair<int, int> nbrPair : adj[topNode])
            {
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;

                if (topDist + nbrDist < dist[nbrNode])
                {
                    auto previousEntry = st.find({dist[nbrNode], nbrNode});
                    if (previousEntry != st.end())
                        st.erase(previousEntry);

                    dist[nbrNode] = topDist + nbrDist;
                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }

        cout << "Shortest Distance from Node " << src << " to Node " << dest << ": " << dist[dest] << endl;
    }
};

int main()
{
    Graph g;
    g.addEdge(1, 6, 14, 0);
    g.addEdge(1, 3, 9, 0);
    g.addEdge(1, 2, 7, 0);
    g.addEdge(2, 3, 10, 0);
    g.addEdge(2, 4, 15, 0);
    g.addEdge(3, 4, 11, 0);
    g.addEdge(3, 6, 2, 0);
    g.addEdge(4, 5, 6, 0);
    g.addEdge(6, 5, 9, 0);

    int n = 6;
    g.dijkstraShortestDist(6, 5, 2);
    return 0;
}