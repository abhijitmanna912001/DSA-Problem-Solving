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

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != NULL)
    {
        fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

bool compareList(ListNode *head1, ListNode *head2)
{
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->val != head2->val)
            return false;
        else
        {
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return true;
}

bool isPalindrome(ListNode *head)
{
    ListNode *midNode = middleNode(head);
    ListNode *head2 = midNode->next;
    midNode->next = NULL;

    ListNode *prev = NULL;
    ListNode *curr = head2;

    head2 = reverseRecursion(prev, curr);
    bool ans = compareList(head, head2);
    return ans;
}

int main()
{

    return 0;
}