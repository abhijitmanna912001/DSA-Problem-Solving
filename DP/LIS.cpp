#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // int solveUsingMemo(vector<int> &num, int curr, int prev, vector<vector<int>> &dp)
    // {
    //     if (curr >= num.size())
    //         return 0;

    //     if (dp[curr][prev + 1] != -1)
    //         return dp[curr][prev + 1];

    //     int include = 0;
    //     if (prev == -1 || num[curr] > num[prev])
    //         include = 1 + solveUsingMemo(num, curr + 1, curr, dp);
    //     int exclude = solveUsingMemo(num, curr + 1, prev, dp);
    //     dp[curr][prev + 1] = max(include, exclude);
    //     return dp[curr][prev + 1];
    // }

    // int solveUsingTabulation(vector<int> &num)
    // {
    //     int n = num.size();
    //     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    //     for (int curr_idx = n - 1; curr_idx >= 0; curr_idx--)
    //     {
    //         for (int prev_idx = curr_idx - 1; prev_idx >= -1; prev_idx--)
    //         {
    //             int include = 0;
    //             if (prev_idx == -1 || num[curr_idx] > num[prev_idx])
    //                 include = 1 + dp[curr_idx + 1][curr_idx + 1];
    //             int exclude = dp[curr_idx + 1][prev_idx + 1];
    //             dp[curr_idx][prev_idx + 1] = max(include, exclude);
    //         }
    //     }
    //     return dp[0][0];
    // }

    // int solveUsingSpaceOptimization(vector<int> &num)
    // {
    //     int n = num.size();
    //     vector<int> prev(n + 1, 0);
    //     vector<int> curr(n + 1, 0);

    //     for (int curr_idx = n - 1; curr_idx >= 0; curr_idx--)
    //     {
    //         for (int prev_idx = curr_idx - 1; prev_idx >= -1; prev_idx--)
    //         {
    //             int include = 0;
    //             if (prev_idx == -1 || num[curr_idx] > num[prev_idx])
    //                 include = 1 + prev[curr_idx + 1];
    //             int exclude = prev[prev_idx + 1];
    //             curr[prev_idx + 1] = max(include, exclude);
    //         }
    //         prev = curr;
    //     }
    //     return prev[0];
    // }

    int solveUsingBS(vector<int> &num)
    {
        vector<int> ans;
        ans.push_back(num[0]);
        for (int i = 1; i < num.size(); i++)
        {
            if (num[i] > ans.back())
                ans.push_back(num[i]);
            else
            {
                int idx = lower_bound(ans.begin(), ans.end(), num[i]) - ans.begin();
                ans[idx] = num[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int ans = solveUsingBS(nums);
        return ans;
    }
};

int main()
{

    return 0;
}