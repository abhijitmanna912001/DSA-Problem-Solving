#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr1 = arr;
    int(*ptr)[5] = &arr;
    cout << (*ptr)[0];
    return 0;
}