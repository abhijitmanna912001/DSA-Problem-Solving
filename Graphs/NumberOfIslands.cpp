#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || grid[i][j] == 'x')
            return 0;

        grid[i][j] = 'x';
        bool marked = 1;

        int remainAns = dfs(grid, i - 1, j) | dfs(grid, i, j - 1) | dfs(grid, i + 1, j) | dfs(grid, i, j + 1);

        return marked || remainAns;
    }

    int numIslands(vector<vector<char>> &grid)
    {
        auto m = grid.size();
        auto n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                ans += dfs(grid, i, j);
        }
        return ans;
    }
};

int main()
{

    return 0;
}