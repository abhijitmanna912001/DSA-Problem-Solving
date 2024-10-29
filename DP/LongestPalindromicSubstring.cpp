#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // M3 - Bottom Up Approach
    int maxlen = 1, start = 0;
    void solveByTabular(string &s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        for (int i = 0; i < n - 1; i++)

            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                start = i;
                maxlen = 2;
            }

        for (int len = 3; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    if (len > maxlen)
                    {
                        maxlen = len;
                        start = i;
                    }
                }
            }
        }
    }

    string longestPalindrome(string s)
    {
        solveByTabular(s);
        return s.substr(start, maxlen);
    }

    // M2 - Top Down Approach
    int maxlen = 1, start = 0;
    bool solveByMemo(string &s, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        bool flag = false;
        if (s[i] == s[j])
            flag = solveByMemo(s, i + 1, j - 1, dp);
        if (flag)
        {
            int currlen = j - i + 1;
            if (currlen > maxlen)
            {
                maxlen = currlen;
                start = i;
            }
        }
        dp[i][j] = flag;
        return dp[i][j];
    }

    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                bool t = solveByMemo(s, i, j, dp);
        return s.substr(start, maxlen);
    }

    // M1 - Recursion Approach
    int maxlen = 1, start = 0;
    bool solveByRecur(string &s, int i, int j)
    {
        if (i >= j)
            return true;

        bool flag = false;
        if (s[i] == s[j])
            flag = solveByRecur(s, i + 1, j - 1);
        if (flag)
        {
            int currlen = j - i + 1;
            if (currlen > maxlen)
            {
                maxlen = currlen;
                start = i;
            }
        }
        return flag;
    }

    string longestPalindrome(string s)
    {
        int n = s.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                bool t = solveByRecur(s, i, j);
        return s.substr(start, maxlen);
    }
};

int main()
{

    return 0;
}