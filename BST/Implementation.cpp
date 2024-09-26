#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
        root->right = insertIntoBST(root->right, data);
    else
        root->left = insertIntoBST(root->left, data);
    return root;
}

void createBST(Node *&root)
{
    cout << "Enter data: " << endl;
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cout << "Enter data: " << endl;
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

Node *minValue(Node *root)
{
    if (root == NULL)
        return NULL;

    Node *temp = root;

    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

Node *maxValue(Node *root)
{
    if (root == NULL)
        return NULL;

    Node *temp = root;

    while (temp->right != NULL)
        temp = temp->right;
    return temp;
}

bool searchInBST(Node *root, int target)
{
    if (root == NULL)
        return false;

    if (root->data == target)
        return true;

    bool leftAns = false;
    bool rightAns = false;

    if (target > root->data)
        rightAns = searchInBST(root->right, target);
    else
        leftAns = searchInBST(root->left, target);
    return leftAns || rightAns;
}

Node *deleteFromBST(Node *root, int target)
{
    if (root == NULL)
        return NULL;

    if (root->data == target)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        else if (root->left != NULL && root->right == NULL)
        {
            Node *childSubTree = root->left;
            delete root;
            return childSubTree;
        }

        else if (root->left == NULL && root->right != NULL)
        {
            Node *childSubTree = root->right;
            delete root;
            return childSubTree;
        }
        else
        {
            Node *maxi = maxValue(root->left);
            root->data = maxi->data;
            root->left = deleteFromBST(root->left, maxi->data);
            return root;
        }
    }

    else if (root->data > target)
        root->left = deleteFromBST(root->left, target);
    else
        root->right = deleteFromBST(root->right, target);
    return root;
}

int main()
{
    Node *root = NULL;
    createBST(root);
    levelOrderTraversal(root);
    cout << endl
         << "Inorder Traversal: ";
    inOrder(root);
    cout << endl
         << "Preorder Traversal: ";
    preOrder(root);
    cout << endl
         << "Postorder Traversal: ";
    postOrder(root);
    Node *minNode = minValue(root);
    Node *maxNode = maxValue(root);
    if (minNode == NULL)
        cout << endl
             << "Minimum value in BST: -1 (Tree is empty)" << endl;
    else
        cout << endl
             << "Minimum value in BST: " << minNode->data << endl;
    if (maxNode == NULL)
        cout << endl
             << "Maximum value in BST: -1 (Tree is empty)" << endl;
    else
        cout << endl
             << "Maximum value in BST: " << maxNode->data << endl;
    int t;
    cin >> t;
    while (t != -1)
    {
        bool ans = searchInBST(root, t);
        if (ans == true)
            cout << "Found" << endl;
        else
            cout << "Not Found" << endl;
        cin >> t;
    }

    int target;
    cin >> target;
    while (target != -1)
    {
        root = deleteFromBST(root, target);
        levelOrderTraversal(root);
        cin >> target;
    }

    return 0;
}