#include <iostream>
using namespace std;

int binarySearch(int arr[], int target, int low, int high)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;

    if (arr[mid] > target)
        return binarySearch(arr, target, low, mid - 1);

    return binarySearch(arr, target, mid + 1, high);
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 12;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = binarySearch(arr, target, 0, n - 1);

    if (result != -1)
        cout << "Target found at index " << result << endl;
    else
        cout << "Target not found" << endl;
    return 0;
}