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
    int D = 0;
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        // int currD = lh + rh + 1; in GFG
        int currD = lh + rh;
        D = max(D, currD);
        return max(lh, rh) + 1;
    }

    int diameterOfBinaryTree2(TreeNode *root)
    {
        height(root);
        return D;
    }

    // Brute Force Method
    // int height(TreeNode *root)
    // {
    //     if (root == NULL)
    //         return 0;
    //     int leftHeight = height(root->left);
    //     int rightHeight = height(root->right);
    //     int maxHeight = max(leftHeight, rightHeight) + 1;
    //     return maxHeight;
    // }

    // int diameterOfBinaryTree(TreeNode *root)
    // {
    //     if (root == NULL)
    //         return 0;
    //     int option1 = diameterOfBinaryTree(root->left);
    //     int option2 = diameterOfBinaryTree(root->right);
    //     int option3 = height(root->left) + height(root->right) + 1;
    //     int diameter = max(option1, max(option2, option3));
    //     return diameter;
    // }
};

int main()
{

    return 0;
}