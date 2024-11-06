#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    // M4 - Space Optimisation
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        const int INF = 1e9 + 1;
        sort(arr2.begin(), arr2.end());
        int n = arr1.size();

        map<int, int> prev_dp;
        prev_dp[-1] = 0;
        for (int i = 0; i < n; ++i)
        {
            map<int, int> curr_dp;
            for (auto [prev, ops] : prev_dp)
            {
                if (arr1[i] > prev)
                {
                    if (curr_dp.find(arr1[i]) == curr_dp.end())
                        curr_dp[arr1[i]] = ops;
                    else
                        curr_dp[arr1[i]] = min(curr_dp[arr1[i]], ops);
                }

                auto it = upper_bound(arr2.begin(), arr2.end(), prev);
                if (it != arr2.end())
                {
                    int replacement = *it;
                    if (curr_dp.find(replacement) == curr_dp.end())
                        curr_dp[replacement] = ops + 1;
                    else
                        curr_dp[replacement] = min(curr_dp[replacement], ops + 1);
                }
            }

            prev_dp = move(curr_dp);
        }

        int result = INF;
        for (auto [_, ops] : prev_dp)
        {
            result = min(result, ops);
        }

        return result == INF ? -1 : result;
    }

    // M3 - Bottom Up Approach
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        const int INF = 1e9 + 1;
        sort(arr2.begin(), arr2.end());
        int n = arr1.size();

        map<int, int> dp;
        dp[-1] = 0;
        for (int i = 0; i < n; ++i)
        {
            map<int, int> new_dp;

            for (auto [prev, ops] : dp)
            {
                if (arr1[i] > prev)
                {
                    if (new_dp.find(arr1[i]) == new_dp.end())
                        new_dp[arr1[i]] = ops;
                    else
                        new_dp[arr1[i]] = min(new_dp[arr1[i]], ops);
                }

                auto it = upper_bound(arr2.begin(), arr2.end(), prev);
                if (it != arr2.end())
                {
                    int replacement = *it;
                    if (new_dp.find(replacement) == new_dp.end())
                        new_dp[replacement] = ops + 1;
                    else
                        new_dp[replacement] = min(new_dp[replacement], ops + 1);
                }
            }
            dp = move(new_dp);
        }

        int result = INF;
        for (auto [_, ops] : dp)
        {
            result = min(result, ops);
        }

        return result == INF ? -1 : result;
    }

    // M2 - Top Down Approach
#define INF (1e9 + 1)
    int solveByMemo(vector<int> &arr1, vector<int> &arr2, int prev, int i, map<pair<int, int>, int> &dp)
    {
        if (i == arr1.size())
            return 0;

        if (dp.find({prev, i}) != dp.end())
            return dp[{prev, i}];

        int op1 = INF;
        if (prev < arr1[i])
            op1 = solveByMemo(arr1, arr2, arr1[i], i + 1, dp);

        int op2 = INF;
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);
        if (it != arr2.end())
        {
            int idx = it - arr2.begin();
            op2 = 1 + solveByMemo(arr1, arr2, arr2[idx], i + 1, dp);
        }
        dp[{prev, i}] = min(op1, op2);
        return dp[{prev, i}];
    }

    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        sort(arr2.begin(), arr2.end());
        map<pair<int, int>, int> dp;
        int ans = solveByMemo(arr1, arr2, -1, 0, dp);
        return ans == INF ? -1 : ans;
    }

    // M1 - Recursive Approach - TLE
#define INF (1e9 + 1)
    int solveByRecur(vector<int> &arr1, vector<int> &arr2, int prev, int i)
    {
        if (i == arr1.size())
            return 0;

        int op1 = INF;
        if (prev < arr1[i])
            op1 = solveByRecur(arr1, arr2, arr1[i], i + 1);

        int op2 = INF;
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);
        if (it != arr2.end())
        {
            int idx = it - arr2.begin();
            op2 = 1 + solveByRecur(arr1, arr2, arr2[idx], i + 1);
        }
        return min(op1, op2);
    }

    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        sort(arr2.begin(), arr2.end());
        int ans = solveByRecur(arr1, arr2, -1, 0);
        return ans == INF ? -1 : ans;
    }
};

int main()
{

    return 0;
}