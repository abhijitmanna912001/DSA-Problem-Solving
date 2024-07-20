#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool TwoPointerApproach(int arr[], int n, int x)
{
    int l = 0, h = n - 1;

    while (l < h)
    {
        int csum = arr[l] + arr[h];
        if (csum == x)
            return true;
        else if (csum > x)
            h--;
        else
            l++;
    }
    return false;
}

bool hasArrayTwoCandidates(vector<int> &arr, int x)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    return TwoPointerApproach(arr.data(), n, x);
}

int main()
{

    return 0;
}