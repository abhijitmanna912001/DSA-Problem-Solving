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

ListNode *reverseRecursion(ListNode *prev, ListNode *curr)
{
    if (curr == NULL)
        return prev;

    ListNode *nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
    ListNode *recurseAns = reverseRecursion(prev, curr);
    return recurseAns;
}

ListNode *reverseList2(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    return reverseRecursion(prev, curr);
}

ListNode *reverseList1(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr != NULL)
    {
        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

int main()
{

    return 0;
}