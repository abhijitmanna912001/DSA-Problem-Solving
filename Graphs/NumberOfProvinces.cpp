#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    void dfs(int src, unordered_map<int, bool> &visited, int n, vector<vector<int>> &isConnected)
    {
        visited[src] = true;
        int col = n;
        int row = src;

        for (int nbrIdx = 0; nbrIdx < col; nbrIdx++)
        {
            int nbr = nbrIdx;
            if (src != nbr && isConnected[row][nbrIdx] == 1)
            {
                if (!visited[nbr])
                    dfs(nbr, visited, n, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int count = 0;
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, n, isConnected);
                count++;
            }
        }
        return count;
    }
};

int main()
{

    return 0;
}