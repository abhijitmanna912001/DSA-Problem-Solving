#include <iostream>
using namespace std;

void rowWiseSum(int arr[4][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum = sum + arr[i][j];
        }
        cout << sum << endl;
    }
}

int main()
{
    int arr[3][4] = {{10, 20, 5, 7}, {2, 4, 6, 8}, {10, 15, 15, 10}};

    int row = 3, col = 4;

    rowWiseSum(arr, row, col);
}