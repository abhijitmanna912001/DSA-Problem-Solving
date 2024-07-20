#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size(), col = matrix[0].size(), n = row * col;
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int rowIndex = mid / col, colIndex = mid % col;
        int currNo = matrix[rowIndex][colIndex];

        if (currNo == target)
            return true;
        else if (target > currNo)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}

int main()
{

    return 0;
}