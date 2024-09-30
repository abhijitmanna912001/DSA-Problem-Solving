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
    Node *inPredecessor(Node *root, Node *x)
    {
        Node *pred = 0;
        Node *curr = root;

        while (curr)
        {
            if (curr->data < x->data)
            {
                pred = curr;
                root = root->right;
            }
            else
                curr = curr->left;
        }
        return pred;
    }
};

int main()
{

    return 0;
}