#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<char>> &matrix, int i, int j, int row, int col, int &maxi)
{
    if (i >= row || j >= col)
        return 0;
    int right = solve(matrix, i, j + 1, row, col, maxi);
    int diagonal = solve(matrix, i + 1, j + 1, row, col, maxi);
    int down = solve(matrix, i + 1, j, row, col, maxi);
    if (matrix[i][j] == '1')
    {
        int ans = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, ans);
        return ans;
    }
    else
        return 0;
}

int maximalSquare(vector<vector<char>> &matrix)
{
    int i = 0, j = 0;
    int row = matrix.size(), col = matrix[0].size();
    int maxi = 0;
    int ans = solve(matrix, i, j, row, col, maxi);
    return maxi * maxi;
}

int main()
{

    return 0;
}