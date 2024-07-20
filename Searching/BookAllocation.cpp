#include <iostream>
#include <numeric>
using namespace std;

bool isPossible(int arr[], int n, int m, int sol)
{
    int pageSum = 0;
    int c = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > sol)
            return false;
        if (pageSum + arr[i] > sol)
        {
            c++;
            pageSum = arr[i];
            if (c > m)
                return false;
        }
        else
            pageSum += arr[i];
    }
    return true;
}

long long findPages(int n, int arr[], int m)
{
    if (m > n)
        return -1;
    int start = 0, end = accumulate(arr, arr + n, 0);
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, n, m, mid))
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