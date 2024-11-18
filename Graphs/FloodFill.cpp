#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isSafe(int newX, int newY, int sr, int sc, vector<vector<int>> &ans,
                int oldColor)
    {
        if (newX >= 0 && newY >= 0 && newX < ans.size() &&
            newY < ans[0].size() && ans[newX][newY] == oldColor)
            return true;
        else
            return false;
    }

    void dfs(int oldColor, int newColor, vector<vector<int>> &ans,
             vector<vector<int>> &image, int sr, int sc)
    {
        ans[sr][sc] = newColor;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int newX = sr + dx[i];
            int newY = sc + dy[i];
            if (isSafe(newX, newY, sr, sc, ans, oldColor))
                dfs(oldColor, newColor, ans, image, newX, newY);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int color)
    {
        vector<vector<int>> ans = image;
        int oldColor = image[sr][sc];
        int newColor = color;
        if (oldColor == newColor)
            return ans;
        dfs(oldColor, newColor, ans, image, sr, sc);
        return ans;
    }
};

int main()
{

    return 0;
}