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

class Solution
{
public:
    int getLength(ListNode *head)
    {
        if (!head)
            return 0;

        return 1 + getLength(head->next);
    }

    ListNode *swapNodes(ListNode *head, int k)
    {
        // CASE 1
        if (!head || !head->next)
            return head;
        int len = getLength(head);
        int lpos = k;
        int rpos = len - k + 1;

        // CASE 2
        if (rpos < lpos)
            swap(lpos, rpos);

        // CASE 3
        if (lpos == rpos)
            return head;

        // CASE 4
        if (len == 2)
        {
            ListNode *nxtNode = head->next;
            nxtNode->next = head;
            head->next = 0;
            head = nxtNode;
            return head;
        }

        // CASE 5
        if (lpos == 1)
        {
            ListNode *lp = 0;
            ListNode *ln = head;
            ListNode *rp = head;
            for (int i = 0; i < rpos - 2; i++)
                rp = rp->next;
            ListNode *rn = rp->next;
            ListNode *rsave = rn->next;

            rn->next = ln->next;
            rp->next = ln;
            ln->next = rsave;
            head = rn;
            return head;
        }

        int noOfNodesBetweenSwapNodes = rpos - lpos - 1;

        // CASE 6
        if (noOfNodesBetweenSwapNodes == 0)
        {
            ListNode *lp = head;
            for (int i = 0; i < lpos - 2; i++)
                lp = lp->next;
            ListNode *ln = lp->next;

            ListNode *rp = head;
            for (int i = 0; i < rpos - 2; i++)
                rp = rp->next;
            ListNode *rn = rp->next;
            ListNode *rsave = rn->next;

            lp->next = rp->next;
            rn->next = rp;
            rp->next = rsave;
            return head;
        }

        // CASE 7
        else
        {
            ListNode *lp = head;
            for (int i = 0; i < lpos - 2; i++)
                lp = lp->next;
            ListNode *ln = lp->next;

            ListNode *rp = head;
            for (int i = 0; i < rpos - 2; i++)
                rp = rp->next;
            ListNode *rn = rp->next;
            ListNode *rsave = rn->next;

            lp->next = rn;
            rn->next = ln->next;
            rp->next = ln;
            ln->next = rsave;
            return head;
        }
    }
};

int main()
{

    return 0;
}