#include <iostream>
#include <vector>

using namespace std;
vector<int> rearrangeArray2(vector<int> &nums)
{
    vector<int> ans(nums.size(), -1);
    int odd = 1, even = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];
        if (num > 0)
        {
            ans[even] = num;
            even += 2;
        }
        else
        {
            ans[odd] = num;
            odd += 2;
        }
    }

    return ans;
};

vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> pos, neg;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
            neg.push_back(nums[i]);
        else
            pos.push_back(nums[i]);
    }
    vector<int> ans;

    int i = 0;
    while (i < pos.size())
    {
        ans.push_back(pos[i]);
        ans.push_back(neg[i]);
        i++;
    }

    return ans;
};

int main()
{

    return 0;
}