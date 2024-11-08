#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // M4- Space Optimisation Approach
    int solveBySO(vector<int> &sat)
    {
        vector<int> curr(sat.size() + 2, 0);
        vector<int> prev(sat.size() + 2, 0);

        for (int i = sat.size() - 1; i >= 0; i--)
        {
            for (int j = sat.size(); j >= 0; j--)
            {
                int include = j * sat[i] + prev[j + 1];
                int exclude = prev[j];
                curr[j] = max(include, exclude);
            }
            prev = curr;
        }

        return prev[1];
    }

    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        return solveBySO(satisfaction);
    }

    // M3- Bottom Up Approach
    int solveByTabu(vector<int> &sat)
    {
        vector<vector<int>> dp(sat.size() + 1, vector<int>(sat.size() + 2, 0));

        for (int i = sat.size() - 1; i >= 0; i--)
        {
            for (int j = sat.size(); j >= 0; j--)
            {
                int include = j * sat[i] + dp[i + 1][j + 1];
                int exclude = dp[i + 1][j];
                dp[i][j] = max(include, exclude);
            }
        }

        return dp[0][1];
    }

    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        return solveByTabu(satisfaction);
    }

    // M2- Top Down Approach
    int solveByMemo(vector<int> &sat, int i, int time, vector<vector<int>> &dp)
    {
        if (i == sat.size())
            return 0;

        if (dp[i][time] != -1)
            return dp[i][time];

        int include = time * sat[i] + solveByMemo(sat, i + 1, time + 1, dp);
        int exclude = solveByMemo(sat, i + 1, time, dp);
        dp[i][time] = max(include, exclude);
        return dp[i][time];
    }

    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(satisfaction.size(), vector<int>(satisfaction.size() + 1, -1));
        return solveByMemo(satisfaction, 0, 1, dp);
    }

    // M1- Recursive Approach
    int solveByRecur(vector<int> &sat, int i, int time)
    {
        if (i == sat.size())
            return 0;

        int include = time * sat[i] + solveByRecur(sat, i + 1, time + 1);
        int exclude = solveByRecur(sat, i + 1, time);
        return max(include, exclude);
    }

    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        return solveByRecur(satisfaction, 0, 1);
    }
};

int main()
{

    return 0;
}