#include <iostream>
using namespace std;

int getOddOccurrence(int arr[], int n)
{
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (start == end)
            return start;
        if (mid & 1)
        {
            if (arr[mid - 1] == arr[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        else
        {
            if (arr[mid] == arr[mid + 1])
                start = mid + 2;
            else
                end = mid;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {10, 10, 2, 2, 3, 3, 5, 5, 6, 6, 7, 10};
    int n = 13;

    int ansIndex = getOddOccurrence(arr, n);

    cout << "Final ans is: " << arr[ansIndex] << endl;
    return 0;
}