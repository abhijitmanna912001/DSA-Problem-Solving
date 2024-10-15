#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int csum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int val = nums[i] == 0 ? -1 : 1;
            csum += val;
            if (csum == 0)
                ans = max(ans, i + 1);
            else if (mp.find(csum) == mp.end())
                mp[csum] = i;
            else
                ans = max(ans, i - mp[csum]);
        }
        return ans;
    }
};

int main()
{

    return 0;
}