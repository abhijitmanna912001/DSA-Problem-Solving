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
    Node *inOrderSuccessor(Node *root, Node *x)
    {
        Node *succ = 0;
        Node *curr = root;

        while (curr)
        {
            if (curr->data > x->data)
            {
                succ = curr;
                curr = curr->left;
            }
            else
                curr = curr->right;
        }
        return succ;
    }
};

int main()
{

    return 0;
}