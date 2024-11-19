#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

class Graph
{
public:
    unordered_map<char, list<pair<char, int>>> adjList;
    void addEdge(char u, char v, int wt, bool direction)
    {
        if (direction == 0)
        {
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
        else
            adjList[u].push_back({v, wt});
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << "->";
            for (auto j : i.second)

                cout << "{" << j.first << ", " << j.second << "}, ";
            cout << endl;
        }
    }

    void bellmanFord(int n, char src)
    {
        vector<int> dist(n, INT_MAX);
        dist[src - 'A'] = 0;

        for (int i = 1; i < n; i++)
        {
            for (auto a : adjList)
            {
                for (auto b : a.second)
                {
                    char u = a.first;
                    char v = b.first;
                    int wt = b.second;
                    if (dist[u - 'A'] != INT_MAX && dist[u - 'A'] + wt < dist[v - 'A'])
                        dist[v - 'A'] = dist[u - 'A'] + wt;
                }
            }
        }

        bool newUpdate = false;
        for (auto a : adjList)
        {
            for (auto b : a.second)
            {
                char u = a.first;
                char v = b.first;
                int wt = b.second;
                if (dist[u - 'A'] != INT_MAX && dist[u - 'A'] + wt < dist[v - 'A'])
                {
                    newUpdate = true;
                    break;
                    dist[v - 'A'] = dist[u - 'A'] + wt;
                }
            }
        }

        if (newUpdate == true)
            cout << "Negative Cycle Present" << endl;
        else
        {
            cout << "No Negative Cycle Present" << endl;
            cout << "Printing Distance Array: " << endl;
            for (auto i : dist)
                cout << i << " ";
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge('A', 'B', -1, 1);
    g.addEdge('A', 'E', 4, 1);
    g.addEdge('B', 'C', 2, 1);
    g.addEdge('B', 'D', 2, 1);
    g.addEdge('B', 'E', 3, 1);
    g.addEdge('C', 'D', -3, 1);
    g.addEdge('D', 'E', 5, 1);
    g.addEdge('D', 'B', 1, 1);

    g.printAdjList();
    g.bellmanFord(5, 'A');
    return 0;
}