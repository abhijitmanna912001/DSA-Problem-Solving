#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void rightViewUtil(Node *root, vector<int> &result, int level, int &maxLevel)
{
    if (root == NULL)
        return;

    // If this is the first node of its level
    if (level > maxLevel)
    {
        result.push_back(root->data);
        maxLevel = level;
    }

    // Recur for the left and right subtrees
    rightViewUtil(root->right, result, level + 1, maxLevel);
    rightViewUtil(root->left, result, level + 1, maxLevel);
}

vector<int> rightView(Node *root)
{
    vector<int> result;
    int maxLevel = -1;
    rightViewUtil(root, result, 0, maxLevel);
    return result;
}

int main()
{

    return 0;
}