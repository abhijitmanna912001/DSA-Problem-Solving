#include <iostream>
#include <vector>
using namespace std;

int searchHelper(vector<int> &arr, int x, int index)
{
    if (index == arr.size())
        return -1;
    if (arr[index] == x)
        return index;
    return searchHelper(arr, x, index + 1);
}

int search(vector<int> &arr, int x)
{
    return searchHelper(arr, x, 0);
}

int main()
{

    return 0;
}