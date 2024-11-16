#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isSafe(int newX, int newY, int row, int col, vector<vector<int>> &diff, int currX, int currY)
    {
        if (newX >= 0 && newY >= 0 && newX < row && newY < col && diff[currX][currY] < diff[newX][newY])
            return true;
        else
            return false;
    }

    int minimumEffortPath(vector<vector<int>> &heights)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> mini;
        int row = heights.size();
        int col = heights[0].size();
        int destX = row - 1;
        int destY = col - 1;

        vector<vector<int>> diff(row, vector<int>(col, INT_MAX));
        diff[0][0] = 0;
        mini.push({0, {0, 0}});

        while (!mini.empty())
        {
            auto topPair = mini.top();
            mini.pop();

            int currDiff = topPair.first;
            pair<int, int> currNodeIdxPair = topPair.second;
            int currX = currNodeIdxPair.first;
            int currY = currNodeIdxPair.second;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                if (isSafe(newX, newY, row, col, diff, currX, currY))
                {
                    int maxDiff = max(currDiff, abs(heights[currX][currY] - heights[newX][newY]));
                    diff[newX][newY] = min(diff[newX][newY], maxDiff);

                    if (newX != destX || newY != destY)
                        mini.push({diff[newX][newY], {newX, newY}});
                }
            }
        }

        return diff[destX][destY];
    }
};

int main()
{

    return 0;
}