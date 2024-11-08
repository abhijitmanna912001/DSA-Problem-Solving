#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // M4 - Space Optimised
    void convertStrstoNumStr(vector<string> &strs, vector<pair<int, int>> &numStrs)
    {
        for (auto str : strs)
        {
            int zeros = 0, ones = 0;
            for (auto ch : str)
            {
                if (ch == '0')
                    zeros++;
                else
                    ones++;
            }
            numStrs.push_back({zeros, ones});
        }
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<pair<int, int>> numStrs;
        convertStrstoNumStr(strs, numStrs);

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto [zeros, ones] : numStrs)
        {
            for (int j = m; j >= zeros; j--)
            {
                for (int k = n; k >= ones; k--)
                {
                    dp[j][k] = max(dp[j][k], 1 + dp[j - zeros][k - ones]);
                }
            }
        }
        return dp[m][n];
    }

    // M3- Bottom Up Approach
    void convertStrstoNumStr(vector<string> &strs, vector<pair<int, int>> &numStrs)
    {
        for (auto str : strs)
        {
            int zeros = 0, ones = 0;
            for (auto ch : str)
            {
                if (ch == '0')
                    zeros++;
                else
                    ones++;
            }
            numStrs.push_back({zeros, ones});
        }
    }

    int solveByTabu(vector<pair<int, int>> &numStrs, int i, int m, int n)
    {
        vector<vector<vector<int>>> dp(numStrs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        for (int i = numStrs.size() - 1; i >= 0; i--)
        {
            int zeros = numStrs[i].first;
            int ones = numStrs[i].second;

            for (int j = m; j >= 0; j--)
            {
                for (int k = n; k >= 0; k--)
                {
                    int include = 0, exclude = 0;

                    if (j - zeros >= 0 && k - ones >= 0)
                        include = 1 + dp[i + 1][j - zeros][k - ones];
                    exclude = dp[i + 1][j][k];
                    dp[i][j][k] = max(include, exclude);
                }
            }
        }

        return dp[0][m][n];
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<pair<int, int>> numStrs;
        convertStrstoNumStr(strs, numStrs);
        return solveByTabu(numStrs, 0, m, n);
    }

    // M2- Top Down Approach
    void convertStrstoNumStr(vector<string> &strs, vector<pair<int, int>> &numStrs)
    {
        for (auto str : strs)
        {
            int zeros = 0, ones = 0;
            for (auto ch : str)
            {
                if (ch == '0')
                    zeros++;
                else
                    ones++;
            }
            numStrs.push_back({zeros, ones});
        }
    }

    int solveByMemo(vector<pair<int, int>> &numStrs, int i, int m, int n, vector<vector<vector<int>>> &dp)
    {
        if (i == numStrs.size())
            return 0;

        if (dp[i][m][n] != -1)
            return dp[i][m][n];

        int zeros = numStrs[i].first;
        int ones = numStrs[i].second;
        int include = 0, exclude = 0;
        if (m - zeros >= 0 && n - ones >= 0)
            include = 1 + solveByMemo(numStrs, i + 1, m - zeros, n - ones, dp);
        exclude = solveByMemo(numStrs, i + 1, m, n, dp);
        dp[i][m][n] = max(include, exclude);
        return dp[i][m][n];
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<pair<int, int>> numStrs;
        convertStrstoNumStr(strs, numStrs);
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solveByMemo(numStrs, 0, m, n, dp);
    }

    // M1- Recursive Approach - TLE
    void convertStrstoNumStr(vector<string> &strs, vector<pair<int, int>> &numStrs)
    {
        for (auto str : strs)
        {
            int zeros = 0, ones = 0;
            for (auto ch : str)
            {
                if (ch == '0')
                    zeros++;
                else
                    ones++;
            }
            numStrs.push_back({zeros, ones});
        }
    }

    int solveByRecur(vector<pair<int, int>> &numStrs, int i, int m, int n)
    {
        if (i == numStrs.size())
            return 0;

        int zeros = numStrs[i].first;
        int ones = numStrs[i].second;
        int include = 0, exclude = 0;
        if (m - zeros >= 0 && n - ones >= 0)
            include = 1 + solveByRecur(numStrs, i + 1, m - zeros, n - ones);
        exclude = solveByRecur(numStrs, i + 1, m, n);
        return max(include, exclude);
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<pair<int, int>> numStrs;
        convertStrstoNumStr(strs, numStrs);
        return solveByRecur(numStrs, 0, m, n);
    }
};

int main()
{

    return 0;
}