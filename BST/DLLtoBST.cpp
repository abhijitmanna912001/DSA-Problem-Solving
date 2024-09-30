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

Node *convertSortedDLLtoBST(Node *&head, int n)
{
    if (head == NULL || n <= 0)
        return NULL;

    Node *leftSubtree = convertSortedDLLtoBST(head, n / 2);

    Node *root = head;
    root->left = leftSubtree;
    head = head->right;

    Node *rightSubtree = convertSortedDLLtoBST(head, n - n / 2 - 1);
    root->right = rightSubtree;
    return root;
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

int main()
{
    Node *first = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);
    Node *sixth = new Node(6);
    Node *seventh = new Node(7);

    first->right = second;
    second->left = first;
    second->right = third;
    third->left = second;
    third->right = fourth;
    fourth->left = third;
    fourth->right = fifth;
    fifth->left = fourth;
    fifth->right = sixth;
    sixth->left = fifth;
    sixth->right = seventh;

    Node *head = first;
    Node *root = convertSortedDLLtoBST(head, 7);
    levelOrderTraversal(root);
    return 0;
}