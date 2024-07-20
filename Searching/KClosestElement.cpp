#include <iostream>
#include <vector>

using namespace std;

int lowerBound(vector<int> &arr, int x)
{
    int start = 0, end = arr.size() - 1;
    int ans = end;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (x > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return ans;
}

vector<int> binarySearch(vector<int> &arr, int k, int x)
{
    int h = lowerBound(arr, x);
    int l = h - 1;

    while (k--)
    {
        if (l < 0)
            h++;
        else if (h >= arr.size())
            l--;
        else if (x - arr[l] > arr[h] - x)
            h++;
        else
            l--;
    }

    return vector<int>(arr.begin() + l + 1, arr.begin() + h);
}

vector<int> twoPointer(vector<int> &arr, int k, int x)
{
    int low = 0, high = arr.size() - 1;
    while (high - low >= k)
    {
        if (x - arr[low] > arr[high] - x)
            low++;
        else
            high--;
    }
    // vector<int> ans;
    // for (int i = low; i <= high; i++)
    // {
    //     ans.push_back(arr[i]);
    // }
    // return ans;
    return vector<int>(arr.begin() + low, arr.begin() + high + 1);
}

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    return binarySearch(arr, k, x);
}

int main()
{

    return 0;
}