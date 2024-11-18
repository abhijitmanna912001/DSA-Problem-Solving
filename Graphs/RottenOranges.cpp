#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isSafe(int newX, int newY, vector<vector<int>> &temp)
    {
        if (newX >= 0 && newY >= 0 && newX < temp.size() && newY < temp[0].size() && temp[newX][newY] == 1)
            return true;
        else
            return false;
    }

    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> temp = grid;
        int minTime = 0;

        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (temp[i][j] == 2)
                    q.push({{i, j}, 0});
            }
        }

        while (!q.empty())
        {
            auto frontNodePair = q.front();
            q.pop();

            auto frontNodeCoordinates = frontNodePair.first;
            int frontNodeTime = frontNodePair.second;
            int tempX = frontNodeCoordinates.first;
            int tempY = frontNodeCoordinates.second;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int newX = tempX + dx[i];
                int newY = tempY + dy[i];

                if (isSafe(newX, newY, temp))
                {
                    q.push({{newX, newY}, frontNodeTime + 1});
                    minTime = max(minTime, frontNodeTime + 1);
                    temp[newX][newY] = 2;
                }
            }
        }

        int freshCount = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (temp[i][j] == 1)
                    freshCount++;
            }
        }

        if (freshCount == 0)
            return minTime;
        else
            return -1;
    }
};

int main()
{

    return 0;
}