#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80};
    int target = 70;

    int res = linearSearch(arr, target);

    if (res != -1)
    {
        cout << "Element found at index: " << res << endl;
    }
    else
        cout << "Element not found in the array" << endl;

    return 0;
}