#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
#define ll long long
    long long minimumDifference(vector<int> &nums)
    {
        int n = nums.size() / 3;
        vector<ll> prefix(nums.size(), -1), suffix(nums.size(), -1);
        ll sum = 0;
        priority_queue<ll> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            pq.push(nums[i]);

            if (pq.size() > n)
            {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == n)
                prefix[i] = sum;
        }

        sum = 0;
        priority_queue<ll, vector<ll>, greater<ll>> pq2;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            sum += nums[i];
            pq2.push(nums[i]);

            if (pq2.size() > n)
            {
                sum -= pq2.top();
                pq2.pop();
            }

            if (pq2.size() == n)
                suffix[i] = sum;
        }

        ll ans = LONG_LONG_MAX;
        for (int i = n - 1; i < 2 * n; i++)
            ans = min(ans, prefix[i] - suffix[i + 1]);
        return ans;
    }
};

int main()
{

    return 0;
}