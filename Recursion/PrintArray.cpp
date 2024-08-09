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

    return 0;
}