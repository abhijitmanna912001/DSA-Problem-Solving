#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // M3 - Bottom Up Approach
    int solveByTabu(vector<int> &sv)
    {
        vector<int> dp(sv.size() + 1, 0);
        for (int i = sv.size() - 1; i >= 0; i--)
        {
            int ans = INT_MIN, total = 0;
            for (int X = 1; X <= 3; X++)
            {
                if (i + X - 1 >= sv.size())
                    break;
                total += sv[i + X - 1];
                ans = max(ans, total - dp[i + X]);
            }
            dp[i] = ans;
        }

        return dp[0];
    }

    string stoneGameIII(vector<int> &stoneValue)
    {
        int ans = solveByTabu(stoneValue);
        if (ans > 0)
            return "Alice";
        if (ans < 0)
            return "Bob";
        return "Tie";
    }

    // M2 - Top Down Approach
    int solveByMemo(vector<int> &sv, int i, vector<int> &dp)
    {
        if (i == sv.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MIN, total = 0;
        for (int X = 1; X <= 3; X++)
        {
            if (i + X - 1 >= sv.size())
                break;
            total += sv[i + X - 1];
            ans = max(ans, total - solveByMemo(sv, i + X, dp));
        }
        dp[i] = ans;
        return dp[i];
    }

    string stoneGameIII(vector<int> &stoneValue)
    {
        vector<int> dp(stoneValue.size() + 1, -1);
        int ans = solveByMemo(stoneValue, 0, dp);
        if (ans > 0)
            return "Alice";
        if (ans < 0)
            return "Bob";
        return "Tie";
    }

    // M1 - Recursive Approach - TLE
    int solveByRecur(vector<int> &sv, int i)
    {
        if (i == sv.size())
            return 0;

        int ans = INT_MIN, total = 0;
        for (int X = 1; X <= 3; X++)
        {
            if (i + X - 1 >= sv.size())
                break;
            total += sv[i + X - 1];
            ans = max(ans, total - solveByRecur(sv, i + X));
        }
        return ans;
    }

    string stoneGameIII(vector<int> &stoneValue)
    {
        int ans = solveByRecur(stoneValue, 0);
        if (ans > 0)
            return "Alice";
        if (ans < 0)
            return "Bob";
        return "Tie";
    }
};

int main()
{

    return 0;
}