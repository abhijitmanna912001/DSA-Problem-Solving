#include <iostream>
#include <vector>
using namespace std;

void printArrayHelper(vector<int> &arr, int index)
{
    if (index < arr.size())
    {
        cout << arr[index] << " ";
        printArrayHelper(arr, index + 1);
    }
}

void printArray(vector<int> &arr)
{
    printArrayHelper(arr, 0);
}

int main()
{
    vector<int> myArray = {2, 3, 5, 5};
    printArray(myArray);
    return 0;
}