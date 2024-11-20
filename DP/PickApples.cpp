#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long long manhattanDist(vector<int> &p1, vector<int> &p2)
    {
        return (long long)abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    long long solveByTD(vector<vector<int>> &points, int a, int b, int i, vector<vector<long long>> &dp)
    {
        if (i == points.size())
            return 0;

        if (dp[a][b] != -1)
            return dp[a][b];

        long long d1 = manhattanDist(points[a], points[i]) + solveByTD(points, i, b, i + 1, dp);

        long long d2 = manhattanDist(points[b], points[i]) + solveByTD(points, a, i, i + 1, dp);

        dp[a][b] = min(d1, d2);

        return dp[a][b];
    }

    long long minDistance(vector<int> &alice, vector<int> &bob,
                          vector<vector<int>> &apples)
    {
        vector<vector<int>> points;
        points.push_back(alice);
        points.push_back(bob);

        for (vector<int> apple : apples)
            points.push_back(apple);

        vector<vector<long long>> dp(points.size(), vector<long long>(points.size(), -1));

        return solveByTD(points, 0, 1, 2, dp);
    }
};

int main()
{

    return 0;
}