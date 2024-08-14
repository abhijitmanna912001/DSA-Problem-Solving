#include <iostream>
#include <vector>
using namespace std;

void merge(vector<long long> &arr, vector<long long> &temp, int start, int mid, int end, long long &count)
{
    int i = start, j = mid + 1, k = start;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            count += mid - i + 1;
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= end)
    {
        temp[k++] = arr[j++];
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i];
    }
}

long long mergeSort(vector<long long> &arr, vector<long long> &temp, int start, int end)
{
    long long count = 0;
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        count += mergeSort(arr, temp, start, mid);
        count += mergeSort(arr, temp, mid + 1, end);
        merge(arr, temp, start, mid, end, count);
    }
    return count;
}

long long int inversionCount(long long arr[], int n)
{
    vector<long long> temp(n, 0);
    vector<long long> arrVec(arr, arr + n);
    return mergeSort(arrVec, temp, 0, n - 1);
}

int main()
{

    return 0;
}