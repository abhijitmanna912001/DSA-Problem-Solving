#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // M4- Space Optimisation
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int swap = 1, noswap = 0;

        for (int i = 1; i < n; i++)
        {
            int currSwap = INT_MAX, currNoswap = INT_MAX;
            if (nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i])
            {
                currNoswap = noswap;
                if (swap != INT_MAX)
                    currSwap = swap + 1;
            }

            if (nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i])
            {
                if (noswap != INT_MAX)
                    currSwap = min(currSwap, noswap + 1);
                currNoswap = min(currNoswap, swap);
            }
            swap = currSwap;
            noswap = currNoswap;
        }

        return min(swap, noswap);
    }

    // M3 - Bottom Up Approach
    int solveByTabu(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(2, INT_MAX));
        dp[n - 1][0] = 0;
        dp[n - 1][1] = 1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums1[i] < nums1[i + 1] && nums2[i] < nums2[i + 1])
            {
                dp[i][0] = dp[i + 1][0];
                dp[i][1] = dp[i + 1][1] + 1;
            }

            if (nums1[i] < nums2[i + 1] && nums2[i] < nums1[i + 1])
            {
                dp[i][0] = min(dp[i][0], dp[i + 1][1]);
                dp[i][1] = min(dp[i][1], dp[i + 1][0] + 1);
            }
        }
        return min(dp[0][0], dp[0][1]);
    }

    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        return solveByTabu(nums1, nums2);
    }

    // M2 - Top Down Approach
    int solveByMemo(vector<int> &nums1, vector<int> &nums2, int i, int prev1, int prev2, vector<vector<int>> &dp, int isswap)
    {
        if (i == nums1.size())
            return 0;

        if (dp[i][isswap] != -1)
            return dp[i][isswap];

        int swap = INT_MAX, noswap = INT_MAX;
        if (prev1 < nums2[i] && prev2 < nums1[i])
            swap = 1 + solveByMemo(nums1, nums2, i + 1, nums2[i], nums1[i], dp, 1);

        if (prev1 < nums1[i] && prev2 < nums2[i])
            noswap = solveByMemo(nums1, nums2, i + 1, nums1[i], nums2[i], dp, 0);
        dp[i][isswap] = min(swap, noswap);
        return dp[i][isswap];
    }

    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));
        return solveByMemo(nums1, nums2, 0, -1, -1, dp, 0);
    }

    // M1 - Recursive Approach - TLE
    int solveByRecur(vector<int> &nums1, vector<int> &nums2, int i, int prev1, int prev2)
    {
        if (i == nums1.size())
            return 0;

        int swap = INT_MAX, noswap = INT_MAX;

        if (prev1 < nums2[i] && prev2 < nums1[i])
            swap = 1 + solveByRecur(nums1, nums2, i + 1, nums2[i], nums1[i]);

        if (prev1 < nums1[i] && prev2 < nums2[i])
            noswap = solveByRecur(nums1, nums2, i + 1, nums1[i], nums2[i]);
        return min(swap, noswap);
    }

    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        return solveByRecur(nums1, nums2, 0, -1, -1);
    }
};

int main()
{

    return 0;
}