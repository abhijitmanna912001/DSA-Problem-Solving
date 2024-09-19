#include <iostream>
#include <queue>
#include <map>
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

int searchInorder(int inOrder[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (inOrder[i] == target)
            return i;
    }
    return -1;
}

Node *
constructTreeFromPostAndInorderTraversal(map<int, int> &valueToIndexMap, int postOrder[], int inOrder[], int &postIndex, int inOrderStart, int inOrderEnd, int size)
{
    if (postIndex < 0 || inOrderStart > inOrderEnd)
        return NULL;

    int element = postOrder[postIndex];
    postIndex--;

    Node *root = new Node(element);

    int position = valueToIndexMap[element];

    root->right = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postOrder, inOrder, postIndex, position + 1, inOrderEnd, size);

    root->left = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postOrder, inOrder, postIndex, inOrderStart, position - 1, size);

    return root;
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

void printInSingleLine(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    printInSingleLine(root->left);
    printInSingleLine(root->right);
}

void createMapping(int inOrder[], int size, map<int, int> &valueToIndexMap)
{
    for (int i = 0; i < size; i++)
    {
        int element = inOrder[i];
        int index = i;
        valueToIndexMap[element] = index;
    }
}

int main()
{
    int inOrder[] = {9, 3, 15, 20, 7};
    int postOrder[] = {9, 15, 7, 20, 3};
    int size = 5;
    int postOrderIndex = size - 1;
    int inOrderStart = 0;
    int inOrderEnd = size - 1;
    map<int, int> valueToIndexMap;
    createMapping(inOrder, size, valueToIndexMap);

    Node *root = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postOrder, inOrder, postOrderIndex, inOrderStart, inOrderEnd, size);
    cout << "Printing the entire tree: " << endl;
    levelOrderTraversal(root);
    return 0;
}