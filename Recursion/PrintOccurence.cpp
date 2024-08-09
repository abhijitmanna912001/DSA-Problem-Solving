#include <iostream>
using namespace std;

void printIndices(int arr[], int target, int index, int size)
{
    // Base case: if the index is out of bounds, stop recursing
    if (index >= size)
    {
        return;
    }

    // If the current element matches the target, print its index
    if (arr[index] == target)
    {
        cout << index << " ";
    }

    // Recurse on the next index
    printIndices(arr, target, index + 1, size);
}

void printIndicesHelper(int arr[], int target, int size)
{
    printIndices(arr, target, 0, size);
}

int main()
{
    int arr[] = {1, 2, 3, 2, 4, 2, 5};
    int target = 2;
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Indices of " << target << ": ";
    printIndicesHelper(arr, target, size);
    cout << endl;

    return 0;
}