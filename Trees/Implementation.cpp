#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// it returns the node of the created tree
Node *createTree()
{
    cout << "Enter the value for Node: " << endl;
    int data;
    cin >> data;
    if (data == -1)
        return NULL;

    // Step 1: create Node
    Node *root = new Node(data);

    // Step 2: create left subtree
    cout << "left of Node: " << root->data << endl;
    root->left = createTree();

    // Step 3: create right subtree
    cout << "right of Node: " << root->data << endl;
    root->right = createTree();
    return root;
}

void preOrderTraversal(Node *root)
{
    // Base Case
    if (root == NULL)
        return;

    // N L R

    // N
    cout << root->data << " ";
    // L
    preOrderTraversal(root->left);
    // R
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root)
{
    // Base Case
    if (root == NULL)
        return;

    // L N R

    // L
    inOrderTraversal(root->left);

    // N
    cout << root->data << " ";

    // R
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    // Base Case
    if (root == NULL)
        return;

    // L R N

    // L
    postOrderTraversal(root->left);

    // R
    postOrderTraversal(root->right);

    // N
    cout << root->data << " ";
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << front->data << " ";
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
        }
    }
}

int main()
{
    Node *root = createTree();
    // cout << root->data << endl;
    cout << "Printing PreOrder: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Printing InOrder: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Printing PostOrder: ";
    postOrderTraversal(root);
    cout << endl;

    cout << "Level Order: ";
    levelOrderTraversal(root);
    cout << endl;
    return 0;
}