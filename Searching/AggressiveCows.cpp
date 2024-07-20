#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSolutionPos(vector<int> &stalls, int n, int k, int sol)
{
    int count = 1;
    int pos = stalls[0];

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - pos >= sol)
        {
            count++;
            pos = stalls[i];
        }
        if (count == k)
            return true;
    }
    return false;
}

int solve(int n, int k, vector<int> &stalls)
{
    sort(stalls.begin(), stalls.end());
    int start = 0, end = stalls[n - 1] - stalls[0];
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isSolutionPos(stalls, n, k, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return ans;
}

int main()
{

    return 0;
}