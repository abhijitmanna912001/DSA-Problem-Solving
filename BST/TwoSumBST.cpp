#include <iostream>
#include <vector>
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
    void storeInOrder(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
            return;
        storeInOrder(root->left, inorder);
        inorder.push_back(root->val);
        storeInOrder(root->right, inorder);
    }

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> inorder;
        storeInOrder(root, inorder);
        int start = 0, end = inorder.size() - 1;

        while (start < end)
        {
            int sum = inorder[start] + inorder[end];
            if (sum == k)
                return true;
            else if (sum > k)
                end--;
            else
                start++;
        }
        return false;
    }
};

int main()
{

    return 0;
}