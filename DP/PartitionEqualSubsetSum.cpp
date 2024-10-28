#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // M4- Space Optimise Approach
    bool solveUsingSO(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);

        curr[target] = 1;
        next[target] = 1;

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int sum = target; sum >= 0; sum--)
            {
                bool include = 0;
                if (sum + arr[idx] <= target)
                    include = next[sum + arr[idx]];
                bool exclude = next[sum];
                curr[sum] = include || exclude;
            }
            next = curr;
        }

        return next[0];
    }

    bool canPartition(vector<int> &nums)
    {
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++)
            totalSum += nums[i];
        if (totalSum & 1)
            return false;
        int target = totalSum / 2;
        bool ans = solveUsingSO(nums, target);
        return ans;
    }

    // M3- Bottom Up Approach
    bool solveUsingTabu(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 2, vector<int>(target + 1, 0));

        for (int row = 0; row <= n; row++)
            dp[row][target] = 1;

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int sum = target; sum >= 0; sum--)
            {
                bool include = 0;
                if (sum + arr[idx] <= target)
                    include = dp[idx + 1][sum + arr[idx]];
                bool exclude = dp[idx + 1][sum];
                dp[idx][sum] = include || exclude;
            }
        }

        return dp[0][0];
    }

    bool canPartition(vector<int> &nums)
    {
        int idx = 0, totalSum = 0;
        for (int i = 0; i < nums.size(); i++)
            totalSum += nums[i];
        if (totalSum & 1)
            return false;
        int currSum = 0, target = totalSum / 2;
        bool ans = solveUsingTabu(nums, target);
        return ans;
    }

    // M2- Top Down Approach
    bool solveUsingMemo(vector<int> &arr, int idx, int sum, int target, vector<vector<int>> &dp)
    {
        if (idx >= arr.size())
            return 0;

        if (sum > target)
            return 0;

        if (sum == target)
            return true;

        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        bool include = solveUsingMemo(arr, idx + 1, sum + arr[idx], target, dp);
        bool exclude = solveUsingMemo(arr, idx + 1, sum, target, dp);
        return dp[idx][sum] = include || exclude;
    }

    bool canPartition(vector<int> &nums)
    {
        int idx = 0, totalSum = 0;
        for (int i = 0; i < nums.size(); i++)
            totalSum += nums[i];
        if (totalSum & 1)
            return false;
        int currSum = 0, target = totalSum / 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
        bool ans = solveUsingMemo(nums, idx, currSum, target, dp);
        return ans;
    }

    // M1- Using Recursion
    bool solveUsingRecursion(vector<int> &arr, int idx, int sum, int target)
    {
        if (idx >= arr.size())
            return 0;

        if (sum == target)
            return true;

        bool include = solveUsingRecursion(arr, idx + 1, sum + arr[idx], target);
        bool exclude = solveUsingRecursion(arr, idx + 1, sum, target);
        return include || exclude;
    }

    bool canPartition(vector<int> &nums)
    {
        int idx = 0, totalSum = 0;
        for (int i = 0; i < nums.size(); i++)
            totalSum += nums[i];
        if (totalSum & 1)
            return false;

        int currSum = 0, target = totalSum / 2;
        bool ans = solveUsingRecursion(nums, idx, currSum, target);
        return ans;
    }
};

int main()
{

    return 0;
}