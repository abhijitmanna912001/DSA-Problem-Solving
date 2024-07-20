#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v)
{
    int size = v.size();
    for (int i = 0; i < size; ++i)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    // int arr[5] = {1, 2, 3, 4, 5};
    // func(arr, 5);

    // int n;
    // cin >> n;
    // int *arr = new int[n];

    // for (int i = 0; i < n; ++i)
    // {
    //     int data;
    //     cin >> data;
    //     arr[i] = data;
    // }

    // for (int i = 0; i < 10; ++i)
    // {
    //     arr[n + i] = 80;
    // }

    // func(arr, n);

    vector<int> v;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int d;
        cin >> d;
        v.push_back(d);
    }
    
    print(v);

    vector<int> v2(5, -1);
    print(v2);
}