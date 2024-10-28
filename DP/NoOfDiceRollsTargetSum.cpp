#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // M4- Space Optimization Approach
    long long int MOD = 1e9 + 7;
    int solveUsingSO(int n, int k, int target)
    {

        vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);

        next[target] = 1;

        for (int dice = n - 1; dice >= 0; dice--)
        {
            for (int sum = target; sum >= 0; sum--)
            {
                int ans = 0;
                for (int face = 1; face <= k; face++)
                {
                    int recurAns = 0;
                    if (sum + face <= target)
                        recurAns = next[sum + face];
                    ans = (ans % MOD + recurAns) % MOD;
                }
                curr[sum] = ans;
            }
            next = curr;
        }

        return next[0];
    }

    int numRollsToTarget(int n, int k, int target)
    {
        int ans = solveUsingSO(n, k, target);
        return ans;
    }

    // M3- Bottom Up Approach
    long long int MOD = 1e9 + 7;
    int solveUsingTabular(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        dp[n][target] = 1;

        for (int dice = n - 1; dice >= 0; dice--)
        {
            for (int sum = target; sum >= 0; sum--)
            {
                int ans = 0;
                for (int face = 1; face <= k; face++)
                {
                    int recurAns = 0;
                    if (sum + face <= target)
                        recurAns = dp[dice + 1][sum + face];
                    ans = (ans % MOD + recurAns) % MOD;
                }
                dp[dice][sum] = ans;
            }
        }

        return dp[0][0];
    }

    int numRollsToTarget(int n, int k, int target)
    {
        int ans = solveUsingTabular(n, k, target);
        return ans;
    }

    // M2- Top Down Approach
    long long int MOD = 1e9 + 7;
    int solveUsingMemo(int n, int k, int target, vector<vector<int>> &dp)
    {
        if (target == 0 && n == 0)
            return 1;

        if (target != 0 && n == 0)
            return 0;

        if (target == 0 && n != 0)
            return 0;

        if (dp[n][target] != -1)
            return dp[n][target];

        int ans = 0;
        for (int i = 1; i <= k; i++)
        {
            int recurAns = 0;
            if (target - i >= 0)
                recurAns = solveUsingMemo(n - 1, k, target - i, dp) % MOD;
            ans = (ans % MOD + recurAns) % MOD;
        }

        dp[n][target] = ans;
        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        int ans = solveUsingMemo(n, k, target, dp);
        return ans;
    }

    // M1- Recursive Approach - TLE
    int solveUsingRecursion(int n, int k, int target)
    {
        if (target == 0 && n == 0)
            return 1;

        if (target != 0 && n == 0)
            return 0;

        if (target == 0 && n != 0)
            return 0;

        int ans = 0;
        for (int i = 1; i <= k; i++)
            ans += solveUsingRecursion(n - 1, k, target - i);
        return ans;
    }

    int numRollsToTarget(int n, int k, int target)
    {
        int ans = solveUsingRecursion(n, k, target);
        return ans;
    }
};

// GFG Dice Throw Problem

class Solution
{
public:
    long long noOfWays(int m, int n, int x)
    {
        vector<long long> curr(x + 1, 0);
        vector<long long> next(x + 1, 0);

        next[0] = 1;

        for (int dice = 1; dice <= n; dice++)
        {
            for (int sum = 0; sum <= x; sum++)
            {
                curr[sum] = 0;
                for (int face = 1; face <= m && sum - face >= 0; face++)
                {
                    curr[sum] += next[sum - face];
                }
            }
            next = curr;
        }
        return next[x];
    }
};

int main()
{

    return 0;
}