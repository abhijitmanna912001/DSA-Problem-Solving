#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v, bool direction)
    {
        if (direction == 1)
            adjList[u].push_back(v);
        else
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void shortestPathBFS(int src, int dest)
    {
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto nbr : adjList[frontNode])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    parent[nbr] = frontNode;
                    visited[nbr] = true;
                }
            }
        }

        vector<int> ans;
        while (dest != -1)
        {
            ans.push_back(dest);
            dest = parent[dest];
        }

        reverse(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 4, 0);
    g.addEdge(4, 1, 0);
    g.addEdge(1, 5, 0);
    g.addEdge(0, 3, 0);
    g.addEdge(3, 5, 0);
    g.addEdge(0, 6, 0);
    g.addEdge(6, 2, 0);
    g.addEdge(2, 5, 0);

    int src = 0;
    int dest = 5;

    g.shortestPathBFS(src, dest);

    return 0;
}