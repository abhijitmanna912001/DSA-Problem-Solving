#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 2. Bottom Up Approach
    int solveUsingTabulation(int n)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        if (n == 0)
            return dp[0];

        dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }

    int fib(int n)
    {
        int ans = solveUsingTabulation(n);
        return ans;
    }

    // 1. Top-down Approach
    // int solveUsingMemo(int n, vector<int> &dp)
    // {
    //     if (n == 0 || n == 1)
    //         return n;

    //     if (dp[n] != -1)
    //         return dp[n];

    //     dp[n] = solveUsingMemo(n - 1, dp) + solveUsingMemo(n - 2, dp);
    //     return dp[n];
    // }

    // int fib(int n)
    // {
    //     vector<int> dp(n + 1, -1);
    //     int ans = solveUsingMemo(n, dp);
    //     return ans;
    // }
};

int main()
{

    return 0;
}