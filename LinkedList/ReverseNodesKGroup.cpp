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
    ListNode *temp = head;
    int len = 0;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL)
        return head;
    if (head->next == NULL)
        return head;
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *nextNode = curr->next;
    int pos = 0;
    int len = getLength(head);
    if (len < k)
        return head;

    while (pos < k)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        pos++;
    }

    ListNode *recursiveAns = NULL;
    if (nextNode != NULL)
    {
        recursiveAns = reverseKGroup(nextNode, k);
        head->next = recursiveAns;
    }
    return prev;
}

int main()
{

    return 0;
}