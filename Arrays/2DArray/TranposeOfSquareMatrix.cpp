#include <iostream>
using namespace std;

void transpose(int arr[4][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

void printArray(int arr[4][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[4][4] = {{1, 2, 3, 4}, {5, 6, 70, 8}, {9, 10, 1, 11}, {12, 24, 46, 89}};
    int row = 4, col = 4;
    cout << endl
         << "Printing before Transpose" << endl;

    printArray(arr, row, col);

    cout << endl
         << "Doing Transpose" << endl;
    transpose(arr, row, col);

    cout << endl
         << "Printing after Transpose" << endl;
    printArray(arr, row, col);
    return 0;
}