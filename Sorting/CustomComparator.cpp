#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool customComparator(int a, int b)
{
    return a < b;
}

int main()
{
    vector<int> arr = {5, 2, 8, 1, 3};
    sort(arr.begin(), arr.end(), customComparator);
    cout << "Sorted array: ";

    for (int num : arr)
    {
        cout << num << " ";
    }

    cout << endl;
    return 0;
}