#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    //M2- Bottom Up Approach
    int solveUsingTabulation(int n)
    {
        vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));
        for (int start_idx = n; start_idx >= 1; start_idx--)
        {
            for (int end_idx = 1; end_idx <= n; end_idx++)
            {
                if (start_idx >= end_idx)
                    continue;
                int ans = INT_MAX;
                for (int i = start_idx; i <= end_idx; i++)
                    ans = min(ans, i + max(dp[start_idx][i - 1], dp[i + 1][end_idx]));
                dp[start_idx][end_idx] = ans;
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n)
    {
        int ans = solveUsingTabulation(n);
        return ans;
    }

    // M1- Top Down Approach
    // int solveUsingMemo(int start, int end, vector<vector<int>> &dp)
    // {
    //     if (start >= end)
    //         return 0;

    //     if (dp[start][end] != -1)
    //         return dp[start][end];

    //     int ans = INT_MAX;
    //     for (int i = start; i <= end; i++)
    //         ans = min(ans, i + max(solveUsingMemo(start, i - 1, dp), solveUsingMemo(i + 1, end, dp)));
    //     dp[start][end] = ans;
    //     return dp[start][end];
    // }

    // int getMoneyAmount(int n)
    // {
    //     int start = 1;
    //     int end = n;
    //     vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    //     int ans = solveUsingMemo(start, end, dp);
    //     return ans;
    // }
};

int main()
{

    return 0;
}