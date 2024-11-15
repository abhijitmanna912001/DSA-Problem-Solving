#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Solution
{
public:
    void topoSortBFS(int n, vector<int> &topoOrder, unordered_map<int, list<int>> &adjList)
    {
        queue<int> q;
        unordered_map<int, int> indegree;
        for (auto i : adjList)
        {
            for (auto nbr : i.second)
                indegree[nbr]++;
        }

        for (int node = 0; node < n; node++)
        {
            if (indegree[node] == 0)
                q.push(node);
        }

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            topoOrder.push_back(frontNode);

            for (auto nbr : adjList[frontNode])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, list<int>> adjList;
        for (vector<int> i : prerequisites)
        {
            int u = i[0];
            int v = i[1];
            adjList[v].push_back(u);
        }

        vector<int> topoSort;
        topoSortBFS(numCourses, topoSort, adjList);
        if (topoSort.size() == numCourses)
            return true;

        else
            return false;
    }
};

int main()
{

    return 0;
}