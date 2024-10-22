#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solveUsingSpaceOptimising(string a, string b)
    {
        vector<int> curr(a.length() + 1, 0);
        vector<int> next(a.length() + 1, 0);

        for (int j_idx = b.length() - 1; j_idx >= 0; j_idx--)
        {
            for (int i_idx = a.length() - 1; i_idx >= 0; i_idx--)
            {
                int ans = 0;
                if (a[i_idx] == b[j_idx])
                    ans = 1 + next[i_idx + 1];
                else
                    ans = max(next[i_idx], curr[i_idx + 1]);
                curr[i_idx] = ans;
            }
            next = curr;
        }
        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int i = 0, j = 0;
        int ans = solveUsingSpaceOptimising(text1, text2);
        return ans;
    }
};

int main()
{

    return 0;
}