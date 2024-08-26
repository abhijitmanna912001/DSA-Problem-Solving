#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *helper1(Node *head, unordered_map<Node *, Node *> &mp)
{
    if (head == 0)
        return 0;

    Node *newHead = new Node(head->val);
    mp[head] = newHead;
    newHead->next = helper1(head->next, mp);
    if (head->random)
    {
        newHead->random = mp[head->random];
    }

    return newHead;
}

Node *copyRandomList2(Node *head)
{
    if (!head)
        return 0;
    Node *it = head;
    while (it)
    {
        Node *clonedNode = new Node(it->val);
        clonedNode->next = it->next;
        it->next = clonedNode;
        it = it->next->next;
    }

    it = head;
    while (it)
    {
        Node *clonedNode = it->next;
        clonedNode->random = it->random ? it->random->next : nullptr;
        it = it->next->next;
    }
    it = head;
    Node *clonedHead = it->next;
    while (it)
    {
        Node *clonedNode = it->next;
        it->next = it->next->next;
        if (clonedNode->next)
            clonedNode->next = clonedNode->next->next;
        it = it->next;
    }
    return clonedHead;
}

Node *copyRandomList(Node *head)
{
    unordered_map<Node *, Node *> mp;
    return helper1(head, mp);
}

int main()
{

    return 0;
}