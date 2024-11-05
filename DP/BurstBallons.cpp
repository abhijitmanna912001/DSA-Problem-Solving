#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // M3- Bottom Up Approach
    int solveByTabular(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        int n = nums.size() - 2;

        for (int start = n; start >= 1; start--)
        {
            for (int end = start; end <= n; end++)
            {
                int coins = INT_MIN;
                for (int i = start; i <= end; i++)
                    coins = max(coins, nums[start - 1] * nums[i] * nums[end + 1] + dp[start][i - 1] + dp[i + 1][end]);
                dp[start][end] = coins;
            }
        }

        return dp[1][n];
    }

    int maxCoins(vector<int> &nums)
    {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        return solveByTabular(nums);
    }

    // M2- Top Down Approach
    int solveByMemo(vector<int> &nums, int start, int end, vector<vector<int>> &dp)
    {
        if (start > end)
            return 0;

        if (dp[start][end] != -1)
            return dp[start][end];

        int coins = INT_MIN;
        for (int i = start; i <= end; i++)
            coins = max(coins, nums[start - 1] * nums[i] * nums[end + 1] + solveByMemo(nums, start, i - 1, dp) + solveByMemo(nums, i + 1, end, dp));
        dp[start][end] = coins;
        return dp[start][end];
    }

    int maxCoins(vector<int> &nums)
    {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        return solveByMemo(nums, 1, nums.size() - 2, dp);
    }

    // M1- Recursive Approach - TLE
    int solveByRecur(vector<int> &nums, int start, int end)
    {
        if (start > end)
            return 0;
        int coins = INT_MIN;
        for (int i = start; i <= end; i++)
            coins = max(coins, nums[start - 1] * nums[i] * nums[end + 1] + solveByRecur(nums, start, i - 1) + solveByRecur(nums, i + 1, end));
        return coins;
    }

    int maxCoins(vector<int> &nums)
    {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        return solveByRecur(nums, 1, nums.size() - 2);
    }
};

int main()
{

    return 0;
}