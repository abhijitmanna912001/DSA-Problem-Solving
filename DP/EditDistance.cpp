#include <iostream>
#include <vector>
using namespace std;

// int solveUsingMemo(string &a, string &b, int i, int j, vector<vector<int>> &dp)
// {
//     if (i == a.length())
//         return b.length() - j;

//     if (j == b.length())
//         return a.length() - i;

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     int ans = 0;

//     if (a[i] == b[j])
//         ans = solveUsingMemo(a, b, i + 1, j + 1, dp);

//     else
//     {
//         int replace = 1 + solveUsingMemo(a, b, i + 1, j + 1, dp);
//         int insert = 1 + solveUsingMemo(a, b, i, j + 1, dp);
//         int remove = 1 + solveUsingMemo(a, b, i + 1, j, dp);
//         ans = min(insert, min(replace, remove));
//     }
//     dp[i][j] = ans;
//     return dp[i][j];
// }

// int solveUsingTabulation(string a, string b)
// {
//     vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, -1));

//     for (int col = 0; col <= b.length(); col++)
//         dp[a.length()][col] = b.length() - col;

//     for (int row = 0; row <= a.length(); row++)
//         dp[row][b.length()] = a.length() - row;

//     for (int i_idx = a.length() - 1; i_idx >= 0; i_idx--)
//     {
//         for (int j_idx = b.length() - 1; j_idx >= 0; j_idx--)
//         {
//             int ans = 0;
//             if (a[i_idx] == b[j_idx])
//                 ans = dp[i_idx + 1][j_idx + 1];

//             else
//             {
//                 int replace = 1 + dp[i_idx + 1][j_idx + 1];
//                 int insert = 1 + dp[i_idx][j_idx + 1];
//                 int remove = 1 + dp[i_idx + 1][j_idx];
//                 ans = min(insert, min(replace, remove));
//             }
//             dp[i_idx][j_idx] = ans;
//         }
//     }

//     return dp[0][0];
// }

int solveUsingSpaceOptimising(string a, string b)
{
    vector<int> curr(a.length() + 1, 0);
    vector<int> next(a.length() + 1, 0);

    for (int row = 0; row <= a.length(); row++)
        next[row] = a.length() - row;

    for (int j_idx = b.length() - 1; j_idx >= 0; j_idx--)
    {
        curr[a.length()] = b.length() - j_idx;
        for (int i_idx = a.length() - 1; i_idx >= 0; i_idx--)
        {
            int ans = 0;
            if (a[i_idx] == b[j_idx])
                ans = next[i_idx + 1];

            else
            {
                int replace = 1 + next[i_idx + 1];
                int insert = 1 + next[i_idx];
                int remove = 1 + curr[i_idx + 1];
                ans = min(insert, min(replace, remove));
            }
            curr[i_idx] = ans;
        }
        next = curr;
    }

    return next[0];
}

int minDistance(string word1, string word2)
{
    int ans = solveUsingSpaceOptimising(word1, word2);
    return ans;
}

int main()
{

    return 0;
}