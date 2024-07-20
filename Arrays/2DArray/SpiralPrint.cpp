#include <iostream>
#include <vector>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
    vector<int> ans;
    int m = matrix.size(), n = matrix[0].size(), total_elements = m * n;
    int startingRow = 0, endingCol = n - 1, endingRow = m - 1, startingCol = 0;

    int count = 0;
    while (count < total_elements)
    {
        for (int i = startingCol; i <= endingCol && count < total_elements; i++)
        {
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;

        for (int i = startingRow; i <= endingRow && count < total_elements; i++)
        {
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;

        for (int i = endingCol; i >= startingCol && count < total_elements; i--)
        {
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;

        for (int i = endingRow; i >= startingRow && count < total_elements; i--)
        {
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}

int main()
{

    return 0;
}