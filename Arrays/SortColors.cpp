#include <iostream>
using namespace std;

void sort012(int a[], int n)
{
    int i = 0, left = 0, right = n - 1;

    while (i <= right)
    {
        if (a[i] == 0)
        {
            swap(a[i], a[left]);
            left++;
            i++;
        }

        else if (a[i] == 2)
        {
            swap(a[i], a[right]);
            right--;
        }
        else
            i++;
    }
}

int main()
{
    int a[] = {2, 0, 2, 1, 1, 0};
    int n = 6;

    cout << "Original array: ";
    
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    sort012(a, n);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}