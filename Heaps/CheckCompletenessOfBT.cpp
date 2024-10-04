#include <iostream>
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
    bool levelOrderTraversal(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        bool nullFound = false;

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            if (temp == NULL)
                nullFound = true;
            else
            {
                if (nullFound)
                    return false;
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return true;
    }

    bool isCompleteTree(TreeNode *root)
    {
        return levelOrderTraversal(root);
    }
};

int main()
{

    return 0;
}