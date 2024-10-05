#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    void storeInorderTraversal(Node *root, vector<int> &inorder)
    {
        if (!root)
            return;
        storeInorderTraversal(root->left, inorder);
        inorder.push_back(root->data);
        storeInorderTraversal(root->right, inorder);
    }

    void replaceUsingPostOrder(Node *root, vector<int> &inorder, int &index)
    {
        if (!root)
            return;
        replaceUsingPostOrder(root->left, inorder, index);
        replaceUsingPostOrder(root->right, inorder, index);
        root->data = inorder[index++];
    }

    void convertToMaxHeapUtil(Node *root)
    {
        vector<int> inorder;
        storeInorderTraversal(root, inorder);
        int index = 0;
        replaceUsingPostOrder(root, inorder, index);
    }
};

int main()
{

    return 0;
}