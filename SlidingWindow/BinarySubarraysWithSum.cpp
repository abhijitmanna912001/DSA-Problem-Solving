#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int start = 0, end = 0, sum = 0, prefixZero = 0, count = 0;

        while (end < nums.size())
        {
            sum += nums[end];
            while (start < end && (sum > goal || nums[start] == 0))
            {
                if (nums[start] == 1)
                    prefixZero = 0;
                else
                    prefixZero += 1;
                sum -= nums[start];
                start++;
            }
            if (sum == goal)
                count += prefixZero + 1;
            end++;
        }
        return count;
    }
};

int main()
{

    return 0;
}