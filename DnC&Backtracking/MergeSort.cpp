#include <iostream>
using namespace std;

void merge(int arr[], int start, int end)
{
    int mid = start + (end - start) / 2;
    int lenLeft = mid - start + 1;
    int lenRight = end - mid;

    int *left = new int[lenLeft];
    int *right = new int[lenRight];

    int k = start;
    for (int i = 0; i < lenLeft; i++)
    {
        left[i] = arr[k];
        k++;
    }
    k = mid + 1;
    for (int i = 0; i < lenRight; i++)
    {
        right[i] = arr[k];
        k++;
    }

    int leftIndex = 0, rightIndex = 0, mainArrayIndex = start;
    while (leftIndex < lenLeft && rightIndex < lenRight)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else
        {
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }
    while (rightIndex < lenRight)
    {
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }
    while (leftIndex < lenLeft)
    {
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }
    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int start, int end)
{
    if (start > end)
        return;
    if (start == end)
        return;
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, end);
}

int main()
{
    int arr[] = {4, 1, 3, 9, 7};
    int size = 5;
    int start = 0, end = size - 1;

    cout << "Before merge sort: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, start, end);

    cout << "After merge sort: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}