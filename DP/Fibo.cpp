#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solveUsingMemo(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
            return n;

        if (dp[n] != -1)
            return dp[n];

        dp[n] = solveUsingMemo(n - 1, dp) + solveUsingMemo(n - 2, dp);
        return dp[n];
    }

    int fib(int n)
    {
        vector<int> dp(n + 1, -1);
        int ans = solveUsingMemo(n, dp);
        return ans;
    }
};

int main()
{

    return 0;
}