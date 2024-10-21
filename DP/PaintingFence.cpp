#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    const int MOD = 1e9 + 7;

    long long solveUsingSpaceOptimise(int n, int k)
    {
        if (n == 1)
            return k;
        if (n == 2)
            return (1LL * k * k) % MOD;
        long long prev2 = k;
        long long prev1 = (1LL * k * k) % MOD;

        long long curr;
        for (int i = 3; i <= n; i++)
        {
            curr = ((k - 1) * (prev1 + prev2) % MOD) % MOD;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    long long countWays(int n, int k)
    {
        return solveUsingSpaceOptimise(n, k);
    }

    long long solveUsingTabulation(int n, int k)
    {
        vector<long long> dp(n + 1, -1);
        dp[1] = k;
        dp[2] = (1LL * k * k) % MOD;
        for (int i = 3; i <= n; i++)
            dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2]) % MOD) % MOD;
        return dp[n];
    }

    long long countWays(int n, int k)
    {
        return solveUsingTabulation(n, k);
    }

    long long solveUsingMemo(int n, int k, vector<long long> &dp)
    {
        if (n == 1)
            return k;
        if (n == 2)
            return (1LL * k * k) % MOD;

        if (dp[n] != -1)
            return dp[n];

        dp[n] = ((k - 1) * (solveUsingMemo(n - 1, k, dp) + solveUsingMemo(n - 2, k, dp)) % MOD) % MOD;
        return dp[n];
    }

    long long countWays(int n, int k)
    {
        vector<long long> dp(n + 1, -1);
        return solveUsingMemo(n, k, dp);
    }

    int main()
    {
        int n = 2;
        int k = 4;
        vector<long long> dp(n + 1, -1);
        int ans = solveUsingTabulation(n, k);
        cout << ans << endl;
        return 0;
    }
};
