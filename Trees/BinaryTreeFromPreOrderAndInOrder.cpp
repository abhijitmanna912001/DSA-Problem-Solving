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
constructTreeFromPreAndInorderTraversal(map<int, int> &valueToIndexMap, int preOrder[], int inOrder[], int &preIndex, int inOrderStart, int inOrderEnd, int size)
{
    if (preIndex >= size || inOrderStart > inOrderEnd)
        return NULL;

    int element = preOrder[preIndex];
    preIndex++;

    Node *root = new Node(element);
    // int position = searchInorder(inOrder, size, element);
    int position = valueToIndexMap[element];

    root->left = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder, inOrder, preIndex, inOrderStart, position - 1, size);

    root->right = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder, inOrder, preIndex, position + 1, inOrderEnd, size);

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
    int preOrder[] = {3, 9, 20, 15, 7};
    int size = 5;
    int preOrderIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = size - 1;
    map<int, int> valueToIndexMap;
    createMapping(inOrder, size, valueToIndexMap);

    Node *root = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder, inOrder, preOrderIndex, inOrderStart, inOrderEnd, size);
    cout << "Printing the entire tree: " << endl;
    levelOrderTraversal(root);
    return 0;
}