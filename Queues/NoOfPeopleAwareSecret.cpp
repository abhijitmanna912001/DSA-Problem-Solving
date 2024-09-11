#include <iostream>
#include <queue>
using namespace std;

class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        const int M = 1e9 + 7;
        int curr = 0;
        int ans = 1;
        queue<pair<int, int>> delayQ, forgetQ;
        delayQ.push({1, 1});
        forgetQ.push({1, 1});
        for (int i = 1; i <= n; i++)
        {
            if (!forgetQ.empty() && forgetQ.front().first + forget <= i)
            {
                auto front = forgetQ.front();
                forgetQ.pop();
                auto no = front.second;
                ans = (ans - no + M) % M;
                curr = (curr - no + M) % M;
            }

            if (!delayQ.empty() && delayQ.front().first + delay <= i)
            {
                auto front = delayQ.front();
                delayQ.pop();
                curr = (curr + front.second) % M;
            }

            if (curr > 0)
            {
                ans = (ans + curr) % M;
                delayQ.push({i, curr});
                forgetQ.push({i, curr});
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}