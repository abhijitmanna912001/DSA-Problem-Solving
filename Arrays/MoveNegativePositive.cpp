#include <iostream>
using namespace std;

void shiftNegative(int arr[], int n)
{
    int right = 0;

    for (int left = 0; left < n; left++)
    {
        if (arr[left] < 0)
        {
            swap(arr[left], arr[right]);
            right++;
        }
    }
}

int main()
{
    int arr[] = {23, -7, 12, -10, -11, 40, 6};
    int n = 7;

    shiftNegative(arr, n);

    cout << "Printing the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}