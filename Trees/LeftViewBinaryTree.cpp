#include <iostream>
#include <vector>
#include <queue>
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

void leftViewUtil(Node *root, vector<int> &result, int level, int &maxLevel)
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
    leftViewUtil(root->left, result, level + 1, maxLevel);
    leftViewUtil(root->right, result, level + 1, maxLevel);
}

vector<int> leftView2(Node *root)
{
    vector<int> result;
    int maxLevel = -1;
    leftViewUtil(root, result, 0, maxLevel);
    return result;
}

vector<int> leftView(Node *root)
{
    vector<int> result;
    if (root == NULL)
        return result;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    bool isFirstElement = true;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            if (!q.empty())
            {
                q.push(NULL);
                isFirstElement = true;
            }
        }
        else
        {
            if (isFirstElement)
            {
                result.push_back(front->data);
                isFirstElement = false;
            }
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
        }
    }
    return result;
}

int main()
{

    return 0;
}