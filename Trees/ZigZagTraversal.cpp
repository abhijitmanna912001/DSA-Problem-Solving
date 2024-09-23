#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        // vector<int> ans; For GFG
        if (!root)
            return ans;
        bool LToRdir = true;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int width = q.size();
            vector<int> oneLevel(width);
            for (int i = 0; i < width; i++)
            {
                TreeNode *front = q.front();
                q.pop();
                int index = LToRdir ? i : width - i - 1;
                oneLevel[index] = front->val;
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            LToRdir = !LToRdir;
            ans.push_back(oneLevel);
            // ans.insert(ans.end(), oneLevel.begin(), oneLevel.end()); For GFG
        }
        return ans;
    }
};

int main()
{

    return 0;
}