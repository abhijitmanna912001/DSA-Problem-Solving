#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
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

        cout << endl
             << "printing adjList" << endl;
        printAdjList();
        cout << endl;
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << "-> {";
            for (auto neighbour : i.second)
                cout << neighbour << ", ";
            cout << "}" << endl;
        }
    }

    bool checkCycleUndirectedBFS(int src)
    {
        queue<int> q;
        unordered_map<int, bool> vis;
        unordered_map<int, int> parent;

        q.push(src);
        vis[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto nbr : adjList[frontNode])
            {
                if (!vis[nbr])
                {
                    q.push(nbr);
                    vis[nbr] = true;
                    parent[nbr] = frontNode;
                }

                else if (vis[nbr] == true && nbr != parent[frontNode])
                {
                    cout << "nbr: " << nbr << endl;
                    cout << "frontNode: " << frontNode << endl;
                    cout << "parent[nbr]: " << parent[nbr] << endl;
                    return true;
                }
            }
        }
        return false;
    }

    bool checkCycleUndirectedDFS(int node, int parent, unordered_map<int, bool> &vis)
    {
        vis[node] = true;

        for (auto neighbor : adjList[node])
        {
            if (!vis[neighbor])
            {
                if (checkCycleUndirectedDFS(neighbor, node, vis))
                    return true;
            }
            else if (neighbor != parent)
                return true;
        }
        return false;
    }

    bool detectCycle()
    {
        unordered_map<int, bool> vis;

        for (auto i : adjList)
        {
            if (!vis[i.first])
            {
                if (checkCycleUndirectedDFS(i.first, -1, vis))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(2, 5, 0);

    int src = 0;
    // bool isCyclic = g.checkCycleUndirectedBFS(src);
    bool isCyclic = g.detectCycle();
    if (isCyclic)
        cout << "Cycle Present" << endl;
    else
        cout << "Cycle Absent" << endl;
    return 0;
}