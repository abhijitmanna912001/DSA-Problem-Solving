#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    // M3- Bottom Up Approach
    int solveByTabu(vector<int> &nums, int target)
    {
        map<pair<int, int>, int> dp;
        dp[{nums.size(), 0}] = 1;

        int total = 0;
        for (auto num : nums)
            total += num;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            for (int sum = -total; sum <= total; sum++)
            {
                int plus = dp.find({i + 1, sum - nums[i]}) != dp.end()
                               ? dp[{i + 1, sum - nums[i]}]
                               : 0;
                int minus = dp.find({i + 1, sum + nums[i]}) != dp.end()
                                ? dp[{i + 1, sum + nums[i]}]
                                : 0;
                dp[{i, sum}] = plus + minus;
            }
        }
        return dp[{0, target}];
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        return solveByTabu(nums, target);
    }

    // M2- Top Down Approach
    int solveByMemo(vector<int> &nums, int target, int i,
                    map<pair<int, int>, int> &dp)
    {
        if (i == nums.size())
            return target == 0 ? 1 : 0;

        if (dp.find({i, target}) != dp.end())
            return dp[{i, target}];

        int plus = solveByMemo(nums, target - nums[i], i + 1, dp);
        int minus = solveByMemo(nums, target + nums[i], i + 1, dp);
        dp[{i, target}] = plus + minus;
        return dp[{i, target}];
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        map<pair<int, int>, int> dp;
        return solveByMemo(nums, target, 0, dp);
    }

    // M1- Recursive Approach
    int solveByRecur(vector<int> &nums, int target, int i)
    {
        if (i == nums.size())
            return target == 0 ? 1 : 0;

        int plus = solveByRecur(nums, target - nums[i], i + 1);
        int minus = solveByRecur(nums, target + nums[i], i + 1);
        return plus + minus;
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        return solveByRecur(nums, target, 0);
    }
};

int main()
{

    return 0;
}
