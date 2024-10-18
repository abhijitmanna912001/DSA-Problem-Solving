#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // M2: Bottom Up Approach
    int solveUsingTabu(vector<int> &coins, int amount)
    {
        int n = amount;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int val = 1; val <= amount; val++)
        {
            int mini = INT_MAX;
            for (int i = 0; i < coins.size(); i++)
            {
                if (val - coins[i] >= 0)
                {
                    int recurseAns = dp[val - coins[i]];
                    if (recurseAns != INT_MAX)
                    {
                        int ans = 1 + recurseAns;
                        mini = min(mini, ans);
                    }
                }
            }
            dp[val] = mini;
        }
        return dp[amount];
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int ans = solveUsingTabu(coins, amount);
        if (ans == INT_MAX)
            return -1;
        else
            return ans;
    }

    // M1: Top Down Approach
    // int solveUsingMemo(vector<int> &coins, int amount, vector<int> &dp)
    // {
    //     if (amount == 0)
    //         return 0;

    //     if (dp[amount] != -1)
    //         return dp[amount];

    //     int mini = INT_MAX;
    //     for (int i = 0; i < coins.size(); i++)
    //     {
    //         if (amount - coins[i] >= 0)
    //         {
    //             int recurseAns = solveUsingMemo(coins, amount - coins[i], dp);
    //             if (recurseAns != INT_MAX)
    //             {
    //                 int ans = 1 + recurseAns;
    //                 mini = min(mini, ans);
    //             }
    //         }
    //     }
    //     dp[amount] = mini;
    //     return dp[amount];
    // }

    // int coinChange(vector<int> &coins, int amount)
    // {
    //     int n = amount;
    //     vector<int> dp(n + 1, -1);
    //     int ans = solveUsingMemo(coins, amount, dp);
    //     if (ans == INT_MAX)
    //         return -1;
    //     else
    //         return ans;
    // }
};

int main()
{

    return 0;
}