#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxLen(vector<int> &arr, int n)
    {
        unordered_map<int, int> mp;
        int csum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            csum += arr[i];
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