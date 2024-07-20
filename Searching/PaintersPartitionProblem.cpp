#include <iostream>
using namespace std;

bool isPossibleSol(int arr[], int n, int k, long long mid)
{
    long long timeSum = 0;
    int c = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            return false;
        if (arr[i] + timeSum > mid)
        {
            c++;
            timeSum = arr[i];
            if (c > k)
                return false;
        }
        else
            timeSum += arr[i];
    }
    return true;
}

long long minTime(int arr[], int n, int k)
{
    long long start = 0, end = 0;
    for (int i = 0; i < n; i++)
    {
        end += arr[i];
    }
    long long ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossibleSol(arr, n, k, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return ans;
}

int main()
{

    return 0;
}