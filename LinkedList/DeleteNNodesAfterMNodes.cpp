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

void linkdelete(struct Node **head, int n, int m)
{
    if (!head)
        return;
    Node *it = *head;
    for (int i = 0; i < m - 1; i++)
    {
        if (!it)
            return;
        it = it->next;
    }
    if (!it)
        return;
    Node *mthNode = it;
    it = mthNode->next;
    for (int i = 0; i < n; i++)
    {
        if (!it)
            break;
        Node *temp = it->next;
        delete it;
        it = temp;
    }
    mthNode->next = it;
    if (it)
    {
        linkdelete(&it, n, m);
    }
}

int main()
{

    return 0;
}