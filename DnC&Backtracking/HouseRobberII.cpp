#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &nums, int start, int end)
{
    if (start > end)
        return 0;
    int option1 = nums[start] + solve(nums, start + 2, end);
    int option2 = 0 + solve(nums, start + 1, end);
    int finalAns = max(option1, option2);
    return finalAns;
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];

    int option1 = solve(nums, 0, n - 2);
    int option2 = solve(nums, 1, n - 1);
    int ans = max(option1, option2);
    return ans;
}

int main()
{

    return 0;
}