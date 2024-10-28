#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // M4 - Binary Search Method
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = min(costs[0], min(costs[1], costs[2]));

        for (int i = 1; i < n; ++i)
        {
            dp[i] = dp[i - 1] + costs[0];

            int j = lower_bound(days.begin(), days.end(), days[i] - 6) - days.begin();
            dp[i] = min(dp[i], (j > 0 ? dp[j - 1] : 0) + costs[1]);

            j = lower_bound(days.begin(), days.end(), days[i] - 29) - days.begin();
            dp[i] = min(dp[i], (j > 0 ? dp[j - 1] : 0) + costs[2]);
        }

        return dp[n - 1];
    }

    // M3- Bottom Up Approach
    int mincostTickets_helper(vector<int> &days, vector<int> &costs, int i)
    {
        int n = days.size();
        int lastDay = days[n - 1];
        vector<int> dp(lastDay + 1, 0);
        int dayIndex = 0;

        for (int i = 1; i <= lastDay; ++i)
        {
            if (i != days[dayIndex])
                dp[i] = dp[i - 1];
            else
            {
                int cost1 = dp[i - 1] + costs[0];
                int cost7 = dp[max(0, i - 7)] + costs[1];
                int cost30 = dp[max(0, i - 30)] + costs[2];
                dp[i] = min(cost1, min(cost7, cost30));
                dayIndex++;
            }
        }

        return dp[lastDay];
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        return mincostTickets_helper(days, costs, 0);
    }

    // M2- Top Down Approach
    // int mincostTickets_helper(vector<int> &days, vector<int> &costs, int i, vector<int> &dp)
    // {
    //     if (i >= days.size())
    //         return 0;

    //     if (dp[i] != -1)
    //         return dp[i];

    //     int cost1 = costs[0] + mincostTickets_helper(days, costs, i + 1, dp);
    //     int passEndDay = days[i] + 7 - 1;
    //     int j = i;
    //     while (j < days.size() && days[j] <= passEndDay)
    //         j++;
    //     int cost7 = costs[1] + mincostTickets_helper(days, costs, j, dp);

    //     passEndDay = days[i] + 30 - 1;
    //     j = i;
    //     while (j < days.size() && days[j] <= passEndDay)
    //         j++;
    //     int cost30 = costs[2] + mincostTickets_helper(days, costs, j, dp);
    //     dp[i] = min(cost1, min(cost7, cost30));
    //     return dp[i];
    // }

    // int mincostTickets(vector<int> &days, vector<int> &costs)
    // {
    //     vector<int> dp(days.size(), -1);
    //     return mincostTickets_helper(days, costs, 0, dp);
    // }

    // M1- Recursion Approach - TLE
    int mincostTickets_helper(vector<int> &days, vector<int> &costs, int i)
    {
        if (i >= days.size())
            return 0;

        int cost1 = costs[0] + mincostTickets_helper(days, costs, i + 1);
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while (j < days.size() && days[j] <= passEndDay)
            j++;
        int cost7 = costs[1] + mincostTickets_helper(days, costs, j);

        passEndDay = days[i] + 30 - 1;
        j = i;
        while (j < days.size() && days[j] <= passEndDay)
            j++;
        int cost30 = costs[2] + mincostTickets_helper(days, costs, j);

        return min(cost1, min(cost7, cost30));
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        return mincostTickets_helper(days, costs, 0);
    }
};

int main()
{

    return 0;
}