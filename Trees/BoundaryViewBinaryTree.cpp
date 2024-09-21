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
    void addLeftBoundary(Node *root, vector<int> &res)
    {
        if (!root)
            return;
        if (root->left || root->right)
            res.push_back(root->data);
        if (root->left)
            addLeftBoundary(root->left, res);
        else if (root->right)
            addLeftBoundary(root->right, res);
    }

    void addLeaves(Node *root, vector<int> &res)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            res.push_back(root->data);
            return;
        }
        addLeaves(root->left, res);
        addLeaves(root->right, res);
    }

    void addRightBoundary(Node *root, vector<int> &res)
    {
        if (!root)
            return;
        if (root->right)
            addRightBoundary(root->right, res);
        else if (root->left)
            addRightBoundary(root->left, res);
        if (root->left || root->right)
            res.push_back(root->data);
    }

    vector<int> boundary(Node *root)
    {
        vector<int> res;
        if (!root)
            return res;
        if (root->left || root->right)
            res.push_back(root->data);
        addLeftBoundary(root->left, res);
        addLeaves(root, res);
        addRightBoundary(root->right, res);
        return res;
    }
};

int main()
{

    return 0;
}