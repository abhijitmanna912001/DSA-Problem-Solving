#include <iostream>
#include <deque>
using namespace std;

void printFirstNegative(int *arr, int n, int k)
{
    deque<int> dq;
    // Process first k elements - first window
    for (int index = 0; index < k; index++)
    {
        int element = arr[index];
        if (element < 0)
            dq.push_back(index);
    }

    // Process remaining windows -> Removal and Addition
    for (int index = k; index < n; index++)
    {
        // Print prev Window
        if (dq.empty())
        {
            cout << "0" << endl;
        }
        else
        {
            cout << arr[dq.front()] << " ";
        }
        // Remove index that are out of range
        if (!dq.empty() && index - dq.front() >= k)
            dq.pop_front();
        // Addition
        if (arr[index] < 0)
        {
            dq.push_back(index);
        }
    }

    // Print Last Window
    if (dq.empty())
    {
        cout << "0" << endl;
    }
    else
    {
        cout << arr[dq.front()] << " ";
    }
}

int main()
{

    return 0;
}