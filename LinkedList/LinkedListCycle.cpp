#include <iostream>
#include <map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    map<ListNode *, bool> table;
    ListNode *temp = head;
    while (temp != NULL)
    {
        if (table[temp] == false)
        {
            table[temp] = true;
        }
        else
            return true;
        temp = temp->next;
    }
    return false;
}

bool hasCycle2(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == slow)
            return true;
    }
    return false;
}

ListNode *getStartingPoint(ListNode *&head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == slow)
            break;
    }

    if (fast == NULL)
    {
        return NULL;
    }

    slow = head;
    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

void removeLoop(ListNode *&head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == slow)
            break;
    }

    if (fast == NULL)
    {
        return;
    }

    slow = head;
    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }
    ListNode *startPoint = slow;
    ListNode *temp = fast;
    while (temp->next != startPoint)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{

    return 0;
}