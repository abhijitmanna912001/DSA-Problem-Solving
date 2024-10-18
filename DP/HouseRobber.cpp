#include <iostream>
#include <vector>
using namespace std;

// M2. Bottom Up Approach
int solveUsingTabular(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    dp[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        int temp = 0;
        if (i + 2 < n)
            temp = dp[i + 2];
        int include = nums[i] + temp;
        int exclude = 0 + dp[i + 1];
        dp[i] = max(include, exclude);
    }
    return dp[0];
}

int rob(vector<int> &nums)
{
    int ans = solveUsingTabular(nums);
    return ans;
}

// M1: Top Down Approach
// int solveUsingMemo(vector<int> &nums, int idx, vector<int> &dp)
// {
//     if (idx >= nums.size())
//         return 0;

//     if (dp[idx] != -1)
//         return dp[idx];

//     int include = nums[idx] + solveUsingMemo(nums, idx + 2, dp);
//     int exclude = 0 + solveUsingMemo(nums, idx + 1, dp);
//     dp[idx] = max(include, exclude);
//     return dp[idx];
// }

// int rob(vector<int> &nums)
// {
//     int idx = 0;
//     int n = nums.size() - 1;
//     vector<int> dp(n + 1, -1);
//     int ans = solveUsingMemo(nums, idx, dp);
//     return ans;
// }

int main()
{

    return 0;
}