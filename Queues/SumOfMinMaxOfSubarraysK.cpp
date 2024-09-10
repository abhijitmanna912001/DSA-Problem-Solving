#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int SumOfKsubArray(vector<int> &nums, int k)
{
    deque<int> dq, dq2;
    int ans = 0;

    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && nums[i] >= nums[dq.back()])
            dq.pop_back();
        while (!dq2.empty() && nums[i] <= nums[dq2.back()])
            dq2.pop_back();
        dq.push_back(i);
        dq2.push_back(i);
    }

    ans += nums[dq.front()] + nums[dq2.front()];

    for (int i = k; i < nums.size(); i++)
    {
        if (!dq.empty() && i - dq.front() >= k)
            dq.pop_front();
        if (!dq2.empty() && i - dq2.front() >= k)
            dq2.pop_front();
        while (!dq.empty() && nums[i] >= nums[dq.back()])
            dq.pop_back();
        while (!dq2.empty() && nums[i] <= nums[dq2.back()])
            dq2.pop_back();
        dq.push_back(i);
        dq2.push_back(i);
        ans += nums[dq.front()] + nums[dq2.front()];
    }

    return ans;
}

int main()
{
    vector<int> nums{2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << SumOfKsubArray(nums, k) << endl;
    return 0;
}