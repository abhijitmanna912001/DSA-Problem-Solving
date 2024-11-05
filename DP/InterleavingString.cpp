#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // M4 - Space Optimisation
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.size(), m = s2.size(), p = s3.size();
        if (n + m != p)
            return false;
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        prev[0] = 1;
        for (int j = 1; j <= m; ++j)
            prev[j] = prev[j - 1] && (s2[j - 1] == s3[j - 1]);

        for (int i = 1; i <= n; ++i)
        {
            curr[0] = prev[0] && (s1[i - 1] == s3[i - 1]);

            for (int j = 1; j <= m; ++j)
            {
                bool fromS1 = (s1[i - 1] == s3[i + j - 1]) && prev[j];
                bool fromS2 = (s2[j - 1] == s3[i + j - 1]) && curr[j - 1];
                curr[j] = fromS1 || fromS2;
            }

            swap(prev, curr);
        }
        return prev[m];
    }

    // M3- Bottom Up Approach
    bool solveByTabu(string &s1, string &s2, string &s3)
    {
        vector<vector<vector<int>>> dp(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1, 0)));

        dp[s1.size()][s2.size()][s3.size()] = 1;
        for (int i = s1.size(); i >= 0; i--)
        {
            for (int j = s2.size(); j >= 0; j--)
            {
                for (int k = s3.size(); k >= 0; k--)
                {
                    if (i == s1.size() && j == s2.size() && k == s3.size())
                        continue;
                    bool flag = false;
                    if (i < s1.size() && s1[i] == s3[k])
                        flag = flag || dp[i + 1][j][k + 1];

                    if (j < s2.size() && s2[j] == s3[k])
                        flag = flag || dp[i][j + 1][k + 1];
                    dp[i][j][k] = flag;
                }
            }
        }

        return dp[0][0][0];
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        return solveByTabu(s1, s2, s3);
    }

    // M2- Top Down Approach
    bool solveByMemo(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<vector<int>>> &dp)
    {
        if (i == s1.size() && j == s2.size() && k == s3.size())
            return true;

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        bool flag = false;
        if (i < s1.size() && s1[i] == s3[k])
            flag = flag || solveByMemo(s1, s2, s3, i + 1, j, k + 1, dp);

        if (j < s2.size() && s2[j] == s3[k])
            flag = flag || solveByMemo(s1, s2, s3, i, j + 1, k + 1, dp);
        dp[i][j][k] = flag;
        return dp[i][j][k];
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        vector<vector<vector<int>>> dp(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1, -1)));
        return solveByMemo(s1, s2, s3, 0, 0, 0, dp);
    }

    // M1- Recursive Approach - TLE
    int solveByRecur(string &s1, string &s2, string &s3, int i, int j, int k)
    {
        if (i == s1.size() && j == s2.size() && k == s3.size())
            return true;

        bool flag = false;
        if (i < s1.size() && s1[i] == s3[k])
            flag = flag || solveByRecur(s1, s2, s3, i + 1, j, k + 1);

        if (j < s2.size() && s2[j] == s3[k])
            flag = flag || solveByRecur(s1, s2, s3, i, j + 1, k + 1);
        return flag;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        return solveByRecur(s1, s2, s3, 0, 0, 0);
    }
};

int main()
{

    return 0;
}