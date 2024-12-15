#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isSafe(int row, int col, char value, vector<vector<char>> &board)
    {
        int n = board.size();
        for (int i = 0; i < n; i++)
        {
            if (board[row][i] == value)
                return false;
        }

        for (int i = 0; i < n; i++)
        {
            if (board[i][col] == value)
                return false;
        }

        for (int i = 0; i < n; i++)
        {
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value)
                return false;
        }
        return true;
    }

    bool solveHelper(vector<vector<char>> &board)
    {
        int n = board.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char ch = '1'; ch <= '9'; ch++)
                    {
                        if (isSafe(i, j, ch, board))
                        {
                            board[i][j] = ch;
                            bool recurAns = solveHelper(board);

                            if (recurAns == true)
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        solveHelper(board);
    }
};

int main()
{

    return 0;
}