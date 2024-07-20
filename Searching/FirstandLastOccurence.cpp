#include <iostream>
using namespace std;

int findLastOccurence(int arr[], int n, int target)
{
    int start = 0, end = n - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    return ans;
}

int findFirstOccurence(int arr[], int n, int target)
{
    int start = 0, end = n - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    return ans;
}

int main()
{
    int arr[] = {10, 20, 30, 30, 30, 30, 40, 50};
    int target = 30;
    int n = sizeof(arr) / sizeof(arr[0]);

    int ansIndex = findLastOccurence(arr, n, target);
    
    if (ansIndex == -1)
    {
        cout << "Element not found" << endl;
    }
    else
        cout << "Element found at index: " << ansIndex << endl;
    return 0;
}