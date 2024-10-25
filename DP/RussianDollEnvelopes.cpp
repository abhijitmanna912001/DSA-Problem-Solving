#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // M2 Binary Search Approach -- Optimal
    int BSApproach(vector<int> &lis, int target)
    {
        int left = 0, right = lis.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (lis[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }

    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b)
             {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                     return a[0] < b[0]; });

        vector<int> heights;
        for (const auto &envelope : envelopes)
            heights.push_back(envelope[1]);

        vector<int> lis;
        for (int height : heights)
        {
            int pos = BSApproach(lis, height);
            if (pos == lis.size())
                lis.push_back(height);
            else
                lis[pos] = height;
        }

        return lis.size();
    }

    // M1 Space Optimised - TLE Error
    // bool check(vector<int> &curr, vector<int> &prev)
    // {
    //     if (prev[0] < curr[0] && prev[1] < curr[1])
    //         return true;
    //     else
    //         return false;
    // }

    // int solve(vector<vector<int>> &envelopes)
    // {
    //     int n = envelopes.size();
    //     vector<int> curr(n + 1, 0);
    //     vector<int> prev(n + 1, 0);

    //     for (int curr_idx = n - 1; curr_idx >= 0; curr_idx--)
    //     {
    //         for (int prev_idx = curr_idx - 1; prev_idx >= -1; prev_idx--)
    //         {
    //             int include = 0;
    //             if (prev_idx == -1 || check(envelopes[curr_idx], envelopes[prev_idx]))
    //                 include = 1 + prev[curr_idx + 1];
    //             int exclude = prev[prev_idx + 1];
    //             curr[prev_idx + 1] = max(include, exclude);
    //         }
    //         prev = curr;
    //     }
    //     return prev[0];
    // }
    // int maxEnvelopes(vector<vector<int>> &envelopes)
    // {
    //     sort(envelopes.begin(), envelopes.end());
    //     int ans = solve(envelopes);
    //     return ans;
    // }
};

int main()
{

    return 0;
}