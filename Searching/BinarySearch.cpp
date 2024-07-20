#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target)
{
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int target = 70;
    int n = sizeof(arr) / sizeof(arr[0]);

    int ansIndex = binarySearch(arr, n, target);

    if (ansIndex == -1)
    {
        cout << "Element not found" << endl;
    }
    else
        cout << "Element found at index: " << ansIndex << endl;

    return 0;
}