#include <iostream>
using namespace std;

static void reverse(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to rotate an array by d elements in counter-clockwise direction.
static void rotateArr(int arr[], int d, int n)
{
    // To handle cases where d is greater than n
    d = d % n;

    // Reverse the first part (0 to d-1)
    reverse(arr, 0, d - 1);

    // Reverse the second part (d to n-1)
    reverse(arr, d, n - 1);

    // Reverse the entire array
    reverse(arr, 0, n - 1);
}

int main()
{

    return 0;
}