#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // M4- Space Optimised Approach
    int solveBySO(vector<int> &prices, int k)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            2, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                for (int limit = 1; limit <= k; limit++)
                {
                    int profit = 0;
                    if (buy)
                    {
                        int buyItProfit = -prices[i] + dp[1][0][limit];
                        int skipProfit = dp[1][1][limit];
                        profit = max(buyItProfit, skipProfit);
                    }
                    else
                    {
                        int sellItProfit = prices[i] + dp[1][1][limit - 1];
                        int skipProfit = dp[1][0][limit];
                        profit = max(sellItProfit, skipProfit);
                    }
                    dp[0][buy][limit] = profit;
                }
            }
            dp[1] = dp[0];
        }
        return dp[0][1][k];
    }

    int maxProfit(int k, vector<int> &prices)
    {
        return solveBySO(prices, k);
    }

    // M3- Bottom Up Approach
    int solveByTabular(vector<int> &prices, int k)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                for (int limit = 1; limit <= k; limit++)
                {
                    int profit = 0;
                    if (buy)
                    {
                        int buyItProfit = -prices[i] + dp[i + 1][0][limit];
                        int skipProfit = dp[i + 1][1][limit];
                        profit = max(buyItProfit, skipProfit);
                    }
                    else
                    {
                        int sellItProfit = prices[i] + dp[i + 1][1][limit - 1];
                        int skipProfit = dp[i + 1][0][limit];
                        profit = max(sellItProfit, skipProfit);
                    }
                    dp[i][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][k];
    }

    int maxProfit(int k, vector<int> &prices)
    {
        return solveByTabular(prices, k);
    }

    // M2 - Top Down Approach
    int solveByMemo(vector<int> &prices, int i, int buy, int limit, vector<vector<vector<int>>> &dp)
    {
        if (i >= prices.size() || limit == 0)
            return 0;

        if (dp[i][buy][limit] != -1)
            return dp[i][buy][limit];

        int profit = 0;
        if (buy)
        {
            int buyItProfit = -prices[i] + solveByMemo(prices, i + 1, 0, limit, dp);
            int skipProfit = solveByMemo(prices, i + 1, 1, limit, dp);
            profit = max(buyItProfit, skipProfit);
        }
        else
        {
            int sellItProfit = prices[i] + solveByMemo(prices, i + 1, 1, limit - 1, dp);
            int skipProfit = solveByMemo(prices, i + 1, 0, limit, dp);
            profit = max(sellItProfit, skipProfit);
        }
        dp[i][buy][limit] = profit;
        return dp[i][buy][limit];
    }

    int maxProfit(int k, vector<int> &prices)
    {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solveByMemo(prices, 0, 1, k, dp);
    }

    // M1 - Recursive Approach - TLE
    int solveByRecur(vector<int> &prices, int i, int buy, int limit)
    {
        if (i >= prices.size() || limit == 0)
            return 0;

        int profit = 0;
        if (buy)
        {
            int buyItProfit = -prices[i] + solveByRecur(prices, i + 1, 0, limit);
            int skipProfit = solveByRecur(prices, i + 1, 1, limit);
            profit = max(buyItProfit, skipProfit);
        }
        else
        {
            int sellItProfit = prices[i] + solveByRecur(prices, i + 1, 1, limit - 1);
            int skipProfit = solveByRecur(prices, i + 1, 0, limit);
            profit = max(sellItProfit, skipProfit);
        }
        return profit;
    }

    int maxProfit(int k, vector<int> &prices)
    {
        return solveByRecur(prices, 0, 1, k);
    }
};

int main()
{

    return 0;
}