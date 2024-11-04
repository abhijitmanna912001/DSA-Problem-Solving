#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // M3 - Bottom Up Approach
    int solveByTabular(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int M = n; M >= 1; M--)
            {
                for (int alice = 0; alice <= 1; alice++)
                {
                    int ans = alice ? INT_MIN : INT_MAX;
                    int total = 0;

                    for (int X = 1; X <= 2 * M; X++)
                    {
                        if (i + X - 1 >= piles.size())
                            break;
                        total += piles[i + X - 1];
                        if (alice)
                            ans = max(ans, total + dp[i + X][max(X, M)][!alice]);
                        else
                            ans = min(ans, dp[i + X][max(X, M)][!alice]);
                    }
                    dp[i][M][alice] = ans;
                }
            }
        }

        return dp[0][1][1];
    }

    int stoneGameII(vector<int> &piles)
    {
        return solveByTabular(piles);
    }

    // M2 - Top Down Approach
    int solveByMemo(vector<int> &piles, int i, int M, int alice, vector<vector<vector<int>>> &dp)
    {
        if (i == piles.size())
            return 0;

        if (dp[i][M][alice] != -1)
            return dp[i][M][alice];

        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;

        for (int X = 1; X <= 2 * M; X++)
        {
            if (i + X - 1 >= piles.size())
                break;
            total += piles[i + X - 1];
            if (alice)
                ans = max(ans, total + solveByMemo(piles, i + X, max(X, M), !alice, dp));
            else
                ans = min(ans, solveByMemo(piles, i + X, max(X, M), !alice, dp));
        }
        dp[i][M][alice] = ans;
        return dp[i][M][alice];
    }

    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        return solveByMemo(piles, 0, 1, true, dp);
    }

    // M1 - Recursive Approach - TLE
    int solveByRecur(vector<int> &piles, int i, int M, int alice)
    {
        if (i == piles.size())
            return 0;

        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;

        for (int X = 1; X <= 2 * M; X++)
        {
            if (i + X - 1 >= piles.size())
                break;
            total += piles[i + X - 1];
            if (alice)
                ans = max(ans, total + solveByRecur(piles, i + X, max(X, M), !alice));
            else
                ans = min(ans, solveByRecur(piles, i + X, max(X, M), !alice));
        }
        return ans;
    }

    int stoneGameII(vector<int> &piles)
    {
        return solveByRecur(piles, 0, 1, true);
    }
};

int main()
{

    return 0;
}