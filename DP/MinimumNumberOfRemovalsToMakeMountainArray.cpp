#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int solveUsingBS(vector<int> &num, vector<int> &lis)
    {
        if (num.size() == 0)
            return 0;

        vector<int> ans;
        lis.push_back(1);
        ans.push_back(num[0]);
        for (int i = 1; i < num.size(); i++)
        {
            if (num[i] > ans.back())
            {
                ans.push_back(num[i]);
                lis.push_back(ans.size());
            }

            else
            {
                int idx = lower_bound(ans.begin(), ans.end(), num[i]) - ans.begin();
                ans[idx] = num[i];
                lis.push_back(idx + 1);
            }
        }
        return ans.size();
    }

    int minimumMountainRemovals(vector<int> &nums)
    {
        vector<int> lis, lds;
        solveUsingBS(nums, lis);
        reverse(nums.begin(), nums.end());
        solveUsingBS(nums, lds);
        reverse(lds.begin(), lds.end());

        int largestMountain = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (lis[i] > 1 && lds[i] > 1)
                largestMountain = max(largestMountain, lis[i] + lds[i] - 1);
        }

        int minRemovals = nums.size() - largestMountain;
        return minRemovals;
    }
};

int main()
{

    return 0;
}