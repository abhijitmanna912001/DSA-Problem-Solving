#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *reverseList(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

Node *addOne(Node *head)
{
    head = reverseList(head);
    int carry = 1;
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;
        temp->data = digit;
        prev = temp;
        temp = temp->next;
        if (carry == 0)
            break;
    }
    if (carry != 0)
    {
        Node *newNode = new Node(carry);
        prev->next = newNode;
    }
    head = reverseList(head);
}

int main()
{

    return 0;
}