#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // M4- Space Optimisation
    int solveBySO(vector<int> &prices, vector<vector<int>> &dp, int &fee)
    {
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                int profit = 0;
                if (buy)
                {
                    int buyItProfit = -prices[i] + dp[1][0];
                    int skipProfit = dp[1][1];
                    profit = max(buyItProfit, skipProfit);
                }
                else
                {
                    int sellItProfit = prices[i] + dp[1][1] - fee;
                    int skipProfit = dp[1][0];
                    profit = max(sellItProfit, skipProfit);
                }
                dp[0][buy] = profit;
            }
            dp[1] = dp[0];
        }
        return dp[0][1];
    }

    int maxProfit(vector<int> &prices, int fee)
    {
        vector<vector<int>> dp(2, vector<int>(2, 0));
        return solveBySO(prices, dp, fee);
    }

    // M3- Bottom Up Approach
    int solveByTabu(vector<int> &prices, int &fee)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));

        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                int profit = 0;
                if (buy)
                {
                    int buyItProfit = -prices[i] + dp[i + 1][0];
                    int skipProfit = dp[i + 1][1];
                    profit = max(buyItProfit, skipProfit);
                }
                else
                {
                    int sellItProfit = prices[i] + dp[i + 1][1] - fee;
                    int skipProfit = dp[i + 1][0];
                    profit = max(sellItProfit, skipProfit);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }

    int maxProfit(vector<int> &prices, int fee)
    {
        return solveByTabu(prices, fee);
    }

    // M2- Top Down Approach
    int solveByMemo(vector<int> &prices, int i, int buy, vector<vector<int>> &dp, int &fee)
    {
        if (i >= prices.size())
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;
        if (buy)
        {
            int buyItProfit = -prices[i] + solveByMemo(prices, i + 1, 0, dp, fee);
            int skipProfit = solveByMemo(prices, i + 1, 1, dp, fee);
            profit = max(buyItProfit, skipProfit);
        }
        else
        {
            int sellItProfit = prices[i] + solveByMemo(prices, i + 1, 1, dp, fee) - fee;
            int skipProfit = solveByMemo(prices, i + 1, 0, dp, fee);
            profit = max(sellItProfit, skipProfit);
        }
        dp[i][buy] = profit;
        return dp[i][buy];
    }

    int maxProfit(vector<int> &prices, int fee)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
        return solveByMemo(prices, 0, 1, dp, fee);
    }

    // M1- Recursive Approach - TLE
    int solveByRecur(vector<int> &prices, int i, int buy, int &fee)
    {
        if (i >= prices.size())
            return 0;

        int profit = 0;
        if (buy)
        {
            int buyItProfit = -prices[i] + solveByRecur(prices, i + 1, 0, fee);
            int skipProfit = solveByRecur(prices, i + 1, 1, fee);
            profit = max(buyItProfit, skipProfit);
        }
        else
        {
            int sellItProfit = prices[i] + solveByRecur(prices, i + 1, 1, fee) - fee;
            int skipProfit = solveByRecur(prices, i + 1, 0, fee);
            profit = max(sellItProfit, skipProfit);
        }
        return profit;
    }

    int maxProfit(vector<int> &prices, int fee)
    {
        return solveByRecur(prices, 0, 1, fee);
    }
};

int main()
{

    return 0;
}