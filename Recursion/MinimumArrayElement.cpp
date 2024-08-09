#include <iostream>
using namespace std;

int findMin(int arr[], int size, int index, int mini)
{
    if (index >= size)
        return mini;

    mini = min(mini, arr[index]);
    return findMin(arr, size, index + 1, mini);
}

int main()
{
    int arr[] = {20, 30, 10, 5, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int mini = arr[0];

    int minVal = findMin(arr, size, 0, mini);
    cout << "Minimum value: " << minVal << endl;
    return 0;
}