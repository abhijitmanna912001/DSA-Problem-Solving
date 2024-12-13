#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    unordered_map<int, bool> rowCheck, topDiagonal, bottomDiagonal;
    bool isSafe(int row, int col, vector<vector<char>> &board)
    {
        if (rowCheck[row] == true)
            return false;

        if (topDiagonal[col - row] == true)
            return false;

        if (bottomDiagonal[row + col] == true)
            return false;
        return true;
    }

    void storeSolution(vector<vector<char>> &board, vector<vector<string>> &ans)
    {
        vector<string> tempSol;
        for (auto vec : board)
        {
            string temp = "";
            for (auto ch : vec)
                temp.push_back(ch);

            tempSol.push_back(temp);
        }
        ans.push_back(tempSol);
    }

    void solve(vector<vector<char>> &board, vector<vector<string>> &ans, int n, int col)
    {
        if (col >= n)
        {
            storeSolution(board, ans);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board))
            {
                board[row][col] = 'Q';
                rowCheck[row] = true;
                topDiagonal[col - row] = true;
                bottomDiagonal[row + col] = true;

                solve(board, ans, n, col + 1);
                board[row][col] = '.';

                rowCheck[row] = 0;
                topDiagonal[col - row] = 0;
                bottomDiagonal[row + col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        int col = 0;
        solve(board, ans, n, col);
        return ans;
    }
};

int main()
{

    return 0;
}