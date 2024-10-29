#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // M4 - Space Optimisation Approach
    int solveBySO(string &s1, string &s2)
    {
        vector<int> prev(s2.size() + 1, 0), curr(s2.size() + 1, 0);
        for (int j = s2.size() - 1; j >= 0; j--)
            prev[j] = s2[j] + prev[j + 1];

        for (int i = s1.size() - 1; i >= 0; i--)
        {
            curr[s2.size()] = s1[i] + prev[s2.size()];

            for (int j = s2.size() - 1; j >= 0; j--)
            {
                if (s1[i] == s2[j])
                    curr[j] = prev[j + 1];
                else
                {
                    int cost1 = s1[i] + prev[j];
                    int cost2 = s2[j] + curr[j + 1];
                    curr[j] = min(cost1, cost2);
                }
            }
            prev = curr;
        }

        return prev[0];
    }

    int minimumDeleteSum(string s1, string s2)
    {
        return solveBySO(s1, s2);
    }

    // M3 - Bottom Up Approach
    int solveByTabular(string &s1, string &s2)
    {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));

        for (int i = s1.size() - 1; i >= 0; i--)
            dp[i][s2.size()] = s1[i] + (i + 1 < s1.size() ? dp[i + 1][s2.size()] : 0);

        for (int i = s2.size() - 1; i >= 0; i--)
            dp[s1.size()][i] = s2[i] + (i + 1 < s2.size() ? dp[s1.size()][i + 1] : 0);

        for (int i = s1.size() - 1; i >= 0; i--)
        {
            for (int j = s2.size() - 1; j >= 0; j--)
            {
                int cost = 0;
                if (s1[i] == s2[j])
                    cost = dp[i + 1][j + 1];
                else
                {
                    int cost1 = s1[i] + dp[i + 1][j];
                    int cost2 = s2[j] + dp[i][j + 1];
                    cost = min(cost1, cost2);
                }
                dp[i][j] = cost;
            }
        }

        return dp[0][0];
    }

    int minimumDeleteSum(string s1, string s2)
    {
        return solveByTabular(s1, s2);
    }

    // M2 - Top Down Approach
    int solveByMemo(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {
        int cost = 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == s1.size() || j == s2.size())
        {
            for (int x = i; x < s1.size(); x++)
                cost += s1[x];
            for (int x = j; x < s2.size(); x++)
                cost += s2[x];
        }
        else if (s1[i] == s2[j])
            cost = solveByMemo(s1, s2, i + 1, j + 1, dp);
        else
        {
            int cost1 = s1[i] + solveByMemo(s1, s2, i + 1, j, dp);
            int cost2 = s2[j] + solveByMemo(s1, s2, i, j + 1, dp);
            cost = min(cost1, cost2);
        }
        dp[i][j] = cost;
        return dp[i][j];
    }

    int minimumDeleteSum(string s1, string s2)
    {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return solveByMemo(s1, s2, 0, 0, dp);
    }

    // M1 - Recursive Approach - TLE
    int solveByRecursion(string &s1, string &s2, int i, int j)
    {
        int cost = 0;
        if (i == s1.size() || j == s2.size())
        {
            for (int x = i; x < s1.size(); x++)
                cost += s1[x];
            for (int x = j; x < s2.size(); x++)
                cost += s2[x];
        }
        else if (s1[i] == s2[j])
            cost = solveByRecursion(s1, s2, i + 1, j + 1);
        else
        {
            int cost1 = s1[i] + solveByRecursion(s1, s2, i + 1, j);
            int cost2 = s2[j] + solveByRecursion(s1, s2, i, j + 1);
            cost = min(cost1, cost2);
        }
        return cost;
    }

    int minimumDeleteSum(string s1, string s2)
    {
        return solveByRecursion(s1, s2, 0, 0);
    }
};

// GFG Problem Solution
class Solution
{

public:
    int findMinCost(string x, string y, int costX, int costY)
    {
        int m = x.size(), n = y.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
            dp[i][0] = i * costX;
        for (int j = 1; j <= n; j++)
            dp[0][j] = j * costY;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (x[i - 1] == y[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    int deleteX = costX + dp[i - 1][j];
                    int deleteY = costY + dp[i][j - 1];
                    dp[i][j] = min(deleteX, deleteY);
                }
            }
        }

        return dp[m][n];
    }
};

int main()
{

    return 0;
}