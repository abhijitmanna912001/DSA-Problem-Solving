#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getLength(ListNode *head)
{
    int length = 0;
    ListNode *temp = head;

    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    return length;
}

ListNode *rotateRight(ListNode *head, int k)
{
    if (!head)
        return 0;
    int len = getLength(head);
    int actualRotateK = (k % len);
    if (actualRotateK == 0)
        return head;
    // For Right Rotation - Clockwise
    int newlastnodePos = len - actualRotateK - 1;
    // For Left Rotation- AntiClockwise
    // int newLastNodePos = actualRotateK - 1;
    ListNode *newLastNode = head;
    for (int i = 0; i < newlastnodePos; i++)
        newLastNode = newLastNode->next;
    ListNode *newHead = newLastNode->next;
    newLastNode->next = 0;
    ListNode *it = newHead;
    while (it->next)
        it = it->next;
    it->next = head;
    return newHead;
}

int main()
{

    return 0;
}