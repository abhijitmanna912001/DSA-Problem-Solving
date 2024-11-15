#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
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

    void printadjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " : {";
            for (auto j : i.second)
                cout << "{" << j.first << " , " << j.second << "}, ";
            cout << "}" << endl;
        }
    }

    void topoOrderDFS(int src, stack<int> &topoOrder, unordered_map<int, bool> &visited)
    {
        visited[src] = true;

        for (auto nbrPair : adj[src])
        {
            int nbrNode = nbrPair.first;
            if (!visited[nbrNode])
                topoOrderDFS(nbrNode, topoOrder, visited);
        }

        topoOrder.push(src);
    }

    void shortestPathDFS(stack<int> &topoOrder, int n)
    {
        vector<int> dist(n, INT_MAX);
        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;

        for (auto nbrPair : adj[src])
        {
            int nbrNode = nbrPair.first;
            int nbrDist = nbrPair.second;

            if (dist[src] + nbrDist < dist[nbrNode])
                dist[nbrNode] = dist[src] + nbrDist;
        }

        while (!topoOrder.empty())
        {
            int src = topoOrder.top();
            topoOrder.pop();

            for (auto nbrPair : adj[src])
            {
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;

                if (dist[src] + nbrDist < dist[nbrNode])
                    dist[nbrNode] = dist[src] + nbrDist;
            }
        }

        cout << "Printing the distance array: " << endl;
        for (auto i : dist)
        {
            cout << i << " ";
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 5, 1);
    g.addEdge(0, 2, 3, 1);
    g.addEdge(1, 3, 3, 1);
    g.addEdge(2, 1, 2, 1);
    g.addEdge(2, 3, 5, 1);
    g.addEdge(2, 4, 6, 1);
    g.addEdge(4, 3, 1, 1);

    g.printadjList();

    int src = 0;
    stack<int> topoOrder;
    unordered_map<int, bool> visited;
    g.topoOrderDFS(src, topoOrder, visited);

    // cout << "Printing TopoOrder" << endl;
    // while (!topoOrder.empty())
    // {
    //     cout << topoOrder.top() << " ";
    //     topoOrder.pop();
    // }

    int n = 5;
    g.shortestPathDFS(topoOrder, n);
    return 0;
}