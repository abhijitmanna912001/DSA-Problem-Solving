#include <iostream>
#include <vector>
using namespace std;

void storeEvenNumbers(vector<int> &arr, vector<int> &evens, int index)
{
    // Base case: If index is out of bounds, return
    if (index == arr.size())
    {
        return;
    }

    // If the current element is even, add it to the evens vector
    if (arr[index] % 2 == 0)
    {
        evens.push_back(arr[index]);
    }

    // Recursive call for the next element
    storeEvenNumbers(arr, evens, index + 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> evens;

    storeEvenNumbers(arr, evens, 0);

    // Print the even numbers
    for (int num : evens)
    {
        cout << num << " ";
    }
    return 0;
}