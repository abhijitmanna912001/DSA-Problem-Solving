#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    int nodeCount(struct Node *root)
    {
        if (!root)
            return 0;
        int left = nodeCount(root->left);
        int right = nodeCount(root->right);
        return 1 + left + right;
    }

    bool isCBT(struct Node *root, int i, int &n)
    {
        if (!root)
            return true;
        if (i > n)
            return false;
        return isCBT(root->left, 2 * i, n) && isCBT(root->right, 2 * i + 1, n);
    }

    bool isMaxOrder(struct Node *root)
    {
        if (!root)
            return true;
        int left = isMaxOrder(root->left);
        int right = isMaxOrder(root->right);
        int ans = false;
        if (!root->left && !root->right)
            ans = true;
        else if (root->left && !root->right)
            ans = root->data > root->left->data;
        else
            ans = root->data > root->left->data && root->data > root->right->data;
        return ans && left && right;
    }

    bool isHeap(struct Node *tree)
    {
        int n = nodeCount(tree);
        int i = 1;
        return isCBT(tree, i, n) && isMaxOrder(tree);
    }
};

int main()
{

    return 0;
}