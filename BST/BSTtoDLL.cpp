#include <iostream>
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

class Solution
{
public:
    void convertBSTtoSortedDLL(Node *root, Node *&head)
    {
        if (root == NULL)
            return;
        convertBSTtoSortedDLL(root->right, head);

        root->right = head;
        if (head != NULL)
            head->left = root;
        head = root;

        convertBSTtoSortedDLL(root->left, head);
    }

    Node *bToDLL(Node *root)
    {
        Node *head = NULL;
        convertBSTtoSortedDLL(root, head);
        return head;
    }
};

int main()
{

    return 0;
}