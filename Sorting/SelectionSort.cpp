#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &v)
{
    int n = v.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = 0; j < n; j++)
        {
            if (v[j] < v[minIndex])
            {
                minIndex = j;
            }
        }

        swap(v[i], v[minIndex]);
    }
}

int main()
{

    return 0;
}