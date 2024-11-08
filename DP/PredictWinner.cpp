#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // M3- Bottom Up Approach
    int solveByTabu(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, 0));

        for (int i = 0; i < nums.size(); i++)
            dp[i][i] = nums[i];

        int i = nums.size();
        for (int start = i - 1; start >= 0; start--)
        {
            for (int end = i; end < nums.size(); end++)
            {
                int diffByStart = nums[start] - dp[start + 1][end];
                int diffByEnd = nums[end] - dp[start][end - 1];
                dp[start][end] = max(diffByStart, diffByEnd);
            }
            i--;
        }

        return dp[0][nums.size() - 1];
    }

    bool predictTheWinner(vector<int> &nums)
    {
        return solveByTabu(nums) >= 0;
    }

    // M2- Top Down Approach
    int solveByMemo(vector<int> &nums, int start, int end, vector<vector<int>> &dp)
    {
        if (start == end)
            return nums[start];

        if (dp[start][end] != -1)
            return dp[start][end];

        int diffByStart = nums[start] - solveByMemo(nums, start + 1, end, dp);
        int diffByEnd = nums[end] - solveByMemo(nums, start, end - 1, dp);
        dp[start][end] = max(diffByStart, diffByEnd);
        return dp[start][end];
    }

    bool predictTheWinner(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return solveByMemo(nums, 0, nums.size() - 1, dp) >= 0;
    }

    // M1- Recursive Approach
    int solveByRecur(vector<int> &nums, int start, int end)
    {
        if (start == end)
            return nums[start];

        int diffByStart = nums[start] - solveByRecur(nums, start + 1, end);
        int diffByEnd = nums[end] - solveByRecur(nums, start, end - 1);
        return max(diffByStart, diffByEnd);
    }

    bool predictTheWinner(vector<int> &nums)
    {
        return solveByRecur(nums, 0, nums.size() - 1) >= 0;
    }
};

int main()
{

    return 0;
}