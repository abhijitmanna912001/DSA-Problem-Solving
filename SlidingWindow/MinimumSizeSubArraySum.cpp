#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int start = 0, end = 0, len = INT_MAX, sum = 0;

        while (end < nums.size())
        {
            sum += nums[end];
            while (sum >= target)
            {
                if (sum >= target)
                    len = min(len, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }

        if (len == INT_MAX)
            return 0;
        else
            return len;
    }
};

int main()
{

    return 0;
}