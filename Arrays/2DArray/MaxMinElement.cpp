#include <iostream>
using namespace std;

int findMax(int arr[4][4], int row, int col)
{
    int maxAns = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] > maxAns)
            {
                maxAns = arr[i][j];
            }
        }
    }
    return maxAns;
}

int findMin(int arr[4][4], int row, int col)
{
    int minAns = INT_MAX;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] < minAns)
            {
                minAns = arr[i][j];
            }
        }
    }
    return minAns;
}

int main()
{
    int arr[4][4] = {{1, 2, 3, 4}, {25, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    int row = 4, col = 4;

    cout << "Maximum no is: " << findMax(arr, row, col) << endl;
    cout << "Minimum no is: " << findMin(arr, row, col) << endl;
    return 0;
}