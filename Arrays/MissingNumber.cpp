#include <iostream>
using namespace std;

int missingNumber2(int n, int nums[])
{
    int start = 0, end = n - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int diff = nums[mid] - mid;

        if (diff == 1)
        {
            start = mid + 1;
        }
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }
    
    if (ans + 1 == 0)
        return n + 1;

    return ans + 1;
}

int missingNumber(int n, int nums[])
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + nums[i];
    }

    int totalSum = n * (n + 1) / 2;
    int ans = totalSum - sum;
    return ans;
}

int main()
{

    return 0;
}