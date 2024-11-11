#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int sumOfGoodSubsequences(vector<int> &nums)
    {
        const int MAX = 100001;
        const int MOD = 1000000007;

        vector<long> dp(MAX, 0);
        vector<long> sum(MAX, 0);
        vector<long> freq(MAX, 0);

        for (int num : nums)
            freq[num]++;

        for (int num : nums)
        {
            dp[num] = (dp[num] + 1) % MOD;
            sum[num] = (sum[num] + num) % MOD;

            if (num - 1 >= 0 && dp[num - 1] > 0)
            {
                dp[num] = (dp[num] + dp[num - 1]) % MOD;
                sum[num] = (sum[num] + sum[num - 1] + dp[num - 1] * num) % MOD;
            }

            if (num + 1 < MAX && dp[num + 1] > 0)
            {
                dp[num] = (dp[num] + dp[num + 1]) % MOD;
                sum[num] = (sum[num] + sum[num + 1] + dp[num + 1] * num) % MOD;
            }
        }

        long ans = 0;
        for (int i = 0; i < MAX; i++)
            ans = (ans + sum[i]) % MOD;
        return static_cast<int>(ans);
    }
};

int main()
{

    return 0;
}