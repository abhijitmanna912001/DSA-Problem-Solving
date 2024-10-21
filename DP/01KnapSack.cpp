#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solveUsingSpaceOptimise(int capacity, vector<int> &wt, vector<int> &profit, int n)
    {
        vector<int> next(capacity + 1, 0);
        vector<int> curr(capacity + 1, 0);

        for (int row = 0; row <= capacity; row++)
            next[row] = 0;

        for (int j = n - 1; j >= 0; j--)
        {
            for (int i = capacity; i >= 0; i--)
            {
                int include = 0;
                if (wt[j] <= i)
                    include = profit[j] + next[i - wt[j]];
                int exclude = next[i];
                curr[i] = max(include, exclude);
            }
            next = curr;
        }

        return curr[capacity];
    }

    int solveUsingTabular(int capacity, vector<int> &wt, vector<int> &profit, int n)
    {
        vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));

        for (int row = 0; row <= capacity; row++)
            dp[row][n] = 0;

        for (int i = 0; i <= capacity; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int include = 0;
                if (wt[j] <= i)
                    include = profit[j] + dp[i - wt[j]][j + 1];
                int exclude = dp[i][j + 1];
                dp[i][j] = max(include, exclude);
            }
        }

        return dp[capacity][0];
    }

    int solveUsingMemo(int capacity, vector<int> &wt, vector<int> &profit, int idx, int n, vector<vector<int>> &dp)
    {
        if (idx >= n)
            return 0;

        if (dp[capacity][idx] != -1)
            return dp[capacity][idx];

        int include = 0;
        if (wt[idx] <= capacity)
            include = profit[idx] + solveUsingMemo(capacity - wt[idx], wt, profit, idx + 1, n, dp);
        int exclude = solveUsingMemo(capacity, wt, profit, idx + 1, n, dp);
        dp[capacity][idx] = max(include, exclude);
        return dp[capacity][idx];
    }

    int solveUsingRecursion(int capacity, vector<int> &wt, vector<int> &profit, int idx, int n)
    {

        if (idx >= n)
            return 0;

        int include = 0;
        if (wt[idx] <= capacity)
            include = profit[idx] + solveUsingRecursion(capacity - wt[idx], wt, profit, idx + 1, n);
        int exclude = solveUsingRecursion(capacity, wt, profit, idx + 1, n);
        return max(include, exclude);
    }

    int knapSack(int W, vector<int> &wt, vector<int> &val)
    {
        int n = wt.size();
        return solveUsingTabular(W, wt, val, n);
        // vector<vector<int>> dp(W + 1, vector<int>(n + 1, -1));
        // return solveUsingMemo(W, wt, val, 0, n, dp);
        // return solveUsingRecursion(W, wt, val, 0, wt.size());
    }
};

int main()
{
    int capacity = 3;

    vector<int> wt = {4, 5, 6};
    vector<int> profit = {1, 2, 3};
    int n = wt.size();
    vector<vector<int>>
        dp(capacity + 1, vector<int>(n + 1, -1));
    Solution sol;

    int ans = sol.knapSack(capacity, wt, profit);

    cout << "Max Profit: " << ans << endl;
    return 0;
}