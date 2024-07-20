#include <iostream>
using namespace std;

int getUnique(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }

    return ans;
}

int main()
{
    int arr[] = {2, 2, 5, 5, 20, 30, 30};
    int n = 7;

    int finalAns = getUnique(arr, n);
    cout << finalAns << endl;
    return 0;
}