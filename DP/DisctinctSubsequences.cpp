#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // M4 - Space Optimised Approach
    int solveBySO(string &s, string &t)
    {
        vector<int> nextRow(s.size() + 1, 0);
        vector<int> currRow(t.size() + 1, 0);

        for (int i = s.size() - 1; i >= 0; i--)
        {
            nextRow[t.size()] = 1;
            for (int j = t.size() - 1; j >= 0; j--)
            {
                long long ans = 0;
                if (s[i] == t[j])
                    ans += nextRow[j + 1];
                ans += nextRow[j];
                currRow[j] = ans;
            }
            nextRow = currRow;
        }

        return nextRow[0];
    }

    int numDistinct(string s, string t)
    {
        return solveBySO(s, t);
    }

    // M3 - Bottom Up Approach
    int solveByTabular(string &s, string &t)
    {
        vector<vector<long long>> dp(s.size() + 1, vector<long long>(t.size() + 1, 0));
        const int MOD = 1e9 + 7;

        for (int i = 0; i <= s.size(); i++)
            dp[i][t.size()] = 1;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = t.size() - 1; j >= 0; j--)
            {
                long long ans = 0;
                if (s[i] == t[j])
                    ans = (ans + dp[i + 1][j + 1]) % MOD;
                ans = (ans + dp[i + 1][j]) % MOD;
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }

    int numDistinct(string s, string t)
    {
        return solveByTabular(s, t);
    }

    // M2 - Top Down Approach
    int solveByMemo(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    {
        if (j == t.size())
            return 1;

        if (i == s.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if (s[i] == t[j])
            ans += solveByMemo(s, t, i + 1, j + 1, dp);
        ans += solveByMemo(s, t, i + 1, j, dp);
        dp[i][j] = ans;
        return dp[i][j];
    }

    int numDistinct(string s, string t)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
        return solveByMemo(s, t, 0, 0, dp);
    }

    // M1 - Recursive Approach - TLE
    int solveByRecur(string &s, string &t, int i, int j)
    {
        if (j == t.size())
            return 1;
        if (i == s.size())
            return 0;
        int ans = 0;
        if (s[i] == t[j])
            ans += solveByRecur(s, t, i + 1, j + 1);
        ans += solveByRecur(s, t, i + 1, j);
        return ans;
    }

    int numDistinct(string s, string t)
    {
        return solveByRecur(s, t, 0, 0);
    }
};

int main()
{

    return 0;
}