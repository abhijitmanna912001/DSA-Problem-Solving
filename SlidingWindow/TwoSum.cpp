#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<pair<int, int>> temp;
        for (int i = 0; i < nums.size(); i++)
        {
            int idx = i;
            int value = nums[i];
            pair<int, int> p = make_pair(value, idx);
            temp.push_back(p);
        }

        sort(temp.begin(), temp.end());
        int start = 0, end = nums.size() - 1;
        vector<int> ans;

        while (start < end)
        {
            int sum = temp[start].first + temp[end].first;
            if (sum == target)
            {
                ans.push_back(temp[start].second);
                ans.push_back(temp[end].second);
                return ans;
            }
            else if (sum > target)
                end--;
            else
                start++;
        }
        return ans;
    }
};

int main()
{

    return 0;
}