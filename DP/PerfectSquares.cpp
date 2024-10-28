#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
    // M3 - Bottom Up Approach
    int numSquareHelper(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            int start = 1;
            while (start * start <= i)
            {
                dp[i] = min(dp[i], 1 + dp[i - start * start]);
                start++;
            }
        }

        return dp[n];
    }

    int numSquares(int n)
    {
        return numSquareHelper(n) - 1;
    }

    // M2 - Top Down Approach
    // int numSquareHelper(int n, vector<int> &dp)
    // {
    //     if (n == 0)
    //         return 1;
    //     if (n < 0)
    //         return 0;

    //     if (dp[n] != -1)
    //         return dp[n];

    //     int ans = INT_MAX, i = 1, end = sqrt(n);
    //     while (i <= end)
    //     {
    //         int perfectSquares = i * i;
    //         int noOfPfSquares = 1 + numSquareHelper(n - perfectSquares, dp);
    //         if (noOfPfSquares < ans)
    //             ans = noOfPfSquares;
    //         i++;
    //     }
    //     dp[n] = ans;
    //     return dp[n];
    // }

    // int numSquares(int n)
    // {
    //     vector<int> dp(n + 1, -1);
    //     return numSquareHelper(n, dp) - 1;
    // }

    // M1 - Recursion Approach - TLE
    int numSquareHelper(int n)
    {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;

        int ans = INT_MAX, i = 1, end = sqrt(n);
        while (i <= end)
        {
            int perfectSquares = i * i;
            int noOfPfSquares = 1 + numSquareHelper(n - perfectSquares);
            if (noOfPfSquares < ans)
                ans = noOfPfSquares;
            i++;
        }
        return ans;
    }

    int numSquares(int n)
    {
        return numSquareHelper(n) - 1;
    }
};

int main()
{

    return 0;
}