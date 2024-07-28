#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int majorityElement(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    return nums[(0 + nums.size() - 1) / 2];
}

int main()
{

    return 0;
}