#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
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

    void dfs(int node, stack<int> &ordering, unordered_map<int, bool> &vis)
    {
        vis[node] = true;
        for (auto nbr : adjList[node])
        {
            if (!vis[nbr])
            {
                dfs(nbr, ordering, vis);
            }
        }
        ordering.push(node);
    }

    void dfs2(int src, unordered_map<int, bool> &vis2, unordered_map<int, list<int>> &adjNew)
    {
        vis2[src] = true;
        for (auto nbr : adjNew[src])
        {
            if (!vis2[nbr])
                dfs2(nbr, vis2, adjNew);
        }
    }

    int getStronglyConnectedComponents(int n)
    {
        stack<int> ordering;
        unordered_map<int, bool> vis;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, ordering, vis);
            }
        }

        unordered_map<int, list<int>> adjNew;
        for (auto a : adjList)
        {
            for (auto b : a.second)
            {
                int u = a.first;
                int v = b;
                adjNew[v].push_back(u);
            }
        }

        int count = 0;
        unordered_map<int, bool> vis2;

        while (!ordering.empty())
        {
            int node = ordering.top();
            ordering.pop();

            if (!vis2[node])
            {
                dfs2(node, vis2, adjNew);
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 0, 1);
    g.addEdge(2, 4, 1);

    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 4, 1);

    g.addEdge(6, 7, 1);

    int n = 8;
    int ans = g.getStronglyConnectedComponents(n);
    cout << ans << endl;
    return 0;
}