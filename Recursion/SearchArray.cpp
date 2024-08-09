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
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2};
    int x = 5;
    int result = search(arr, x);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}