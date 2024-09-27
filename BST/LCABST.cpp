#include <iostream>
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;

        if (p->val < root->val && q->val < root->val)
        {
            TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
            return leftAns;
        }

        if (p->val > root->val && q->val > root->val)
        {
            TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);
            return rightAns;
        }

        return root;
    }
};

int main()
{

    return 0;
}