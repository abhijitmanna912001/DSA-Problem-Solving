#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int srcx, int srcy, int newx, int newy, int maze[][4], int row, int col, vector<vector<bool>> &visited)
{
    if ((newx >= 0 && newx < row) && (newy >= 0 && newy < col) && maze[newx][newy] == 1 && visited[newx][newy] == false)
        return true;
    else
        return false;
}

void printAllPath(int maze[][4], int row, int col, int srcx, int srcy, string &output, vector<vector<bool>> &visited)
{
    if (srcx == row - 1 && srcy == col - 1)
    {
        cout << output << endl;
        return;
    }

    // UP
    int newx = srcx - 1;
    int newy = srcy;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited))
    {
        visited[newx][newy] = true;
        output.push_back('U');
        printAllPath(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        visited[newx][newy] = false;
    }

    // RIGHT
    newx = srcx;
    newy = srcy + 1;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited))
    {
        visited[newx][newy] = true;
        output.push_back('R');
        printAllPath(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        visited[newx][newy] = false;
    }

    // DOWN
    newx = srcx + 1;
    newy = srcy;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited))
    {
        visited[newx][newy] = true;
        output.push_back('D');
        printAllPath(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        visited[newx][newy] = false;
    }

    // LEFT
    newx = srcx;
    newy = srcy - 1;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited))
    {
        visited[newx][newy] = true;
        output.push_back('L');
        printAllPath(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        visited[newx][newy] = false;
    }
}

// GFG Solution
// bool isSafe(int newx, int newy, vector<vector<int>> &mat, int n, vector<vector<bool>> &visited) {
//         if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && mat[newx][newy] == 1 && visited[newx][newy] == false)
//             return true;
//         else
//             return false;
//     }

//     void findPathsUtil(vector<vector<int>> &mat, int n, int srcx, int srcy, string &output, vector<string> &paths, vector<vector<bool>> &visited) {
//         // If destination is reached, store the path
//         if (srcx == n - 1 && srcy == n - 1)
//         {
//             paths.push_back(output);
//             return;
//         }

//         // Define the four possible movements and their respective directions
//         int moveX[] = {-1, 1, 0, 0}; // U, D, L, R
//         int moveY[] = {0, 0, -1, 1};
//         char dir[] = {'U', 'D', 'L', 'R'};

//         // Explore all possible directions
//         for (int i = 0; i < 4; i++)
//         {
//             int newx = srcx + moveX[i];
//             int newy = srcy + moveY[i];

//             if (isSafe(newx, newy, mat, n, visited))
//             {
//                 visited[newx][newy] = true;
//                 output.push_back(dir[i]);
//                 findPathsUtil(mat, n, newx, newy, output, paths, visited);
//                 output.pop_back();
//                 visited[newx][newy] = false;
//             }
//         }
//     }

//     vector<string> findPath(vector<vector<int>> &mat) {
//         int n = mat.size();
//         vector<string> paths;

//         // Edge case: If the source or destination is blocked
//         if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0)
//             return paths;

//         vector<vector<bool>> visited(n, vector<bool>(n, false));
//         string output = "";

//         // Start from the source
//         visited[0][0] = true;
//         findPathsUtil(mat, n, 0, 0, output, paths, visited);

//         // Sort the paths lexicographically
//         sort(paths.begin(), paths.end());

//         return paths;
//     }

int main()
{
    int maze[4][4] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int row = 4, col = 4;
    int srcx = 0, srcy = 0;
    string output = "";
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    if (maze[0][0] == 0)
    {
        cout << "No path exists" << endl;
    }
    else
    {
        visited[srcx][srcy] = true;
        printAllPath(maze, row, col, srcx, srcy, output, visited);
    }
    return 0;
}