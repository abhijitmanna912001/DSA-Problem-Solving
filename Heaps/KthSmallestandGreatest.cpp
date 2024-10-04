#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<int> &arr, int k)
    {
        priority_queue<int> pq;
        for (int i = 0; i < k; i++)
        {
            int element = arr[i];
            pq.push(element);
        }

        for (int i = k; i < arr.size(); i++)
        {
            int element = arr[i];
            if (element < pq.top())
            {
                pq.pop();
                pq.push(element);
            }
        }

        int ans = pq.top();
        return ans;
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++)
        {
            int element = nums[i];
            pq.push(element);
        }

        for (int i = k; i < nums.size(); i++)
        {
            int element = nums[i];
            if (element > pq.top())
            {
                pq.pop();
                pq.push(element);
            }
        }

        int ans = pq.top();
        return ans;
    }
};

int main()
{

    return 0;
}