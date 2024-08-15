#include <iostream>
#include <vector>
using namespace std;

void permuteUniqueHelper(vector<int> &nums, vector<vector<int>> &ans, int start)
{
    if (start == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); i++)
    {
        swap(nums[i], nums[start]);
        permuteUniqueHelper(nums, ans, start + 1);
        swap(nums[i], nums[start]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    permuteUniqueHelper(nums, ans, 0);
    return ans;
}

int main()
{

    return 0;
}