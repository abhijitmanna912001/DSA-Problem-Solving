#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {2, 4, 6, 8, 10};
    int target = 10;
    int n = 5;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            cout << "Target found" << endl;
            break;
        }
    }

    return 0;
}