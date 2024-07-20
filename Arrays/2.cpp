#include <iostream>
#include <limits>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = {5, 8, 9, 12, 13};

    int size = 5;
    printArray(arr, size);
    cout << INT_MIN << endl;
    cout << INT_MAX << endl;

    // cout << arr[0] << endl;
    // cout << arr[3] << endl;
}