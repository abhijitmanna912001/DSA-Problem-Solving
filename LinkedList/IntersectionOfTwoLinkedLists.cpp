#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *A = headA;
    ListNode *B = headB;

    while (A->next && B->next)
    {
        if (A == B)
            return A;
        A = A->next;
        B = B->next;
    }

    if (A->next == 0)
    {
        int blen = 0;
        while (B->next)
        {
            blen++;
            B = B->next;
        }

        while (blen--)
        {
            headB = headB->next;
        }
    }

    else
    {
        int alen = 0;
        while (A->next)
        {
            alen++;
            A = A->next;
        }

        while (alen--)
        {
            headA = headA->next;
        }
    }

    while (headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}

int main()
{

    return 0;
}