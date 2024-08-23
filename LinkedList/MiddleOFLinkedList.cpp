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

int getLength(ListNode *&head)
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

ListNode *middleNode(ListNode *head)
{
    int n = getLength(head);
    int pos = n / 2 + 1;
    int currPos = 1;
    ListNode *temp = head;
    while (currPos != pos)
    {
        currPos++;
        temp = temp->next;
    }
    return temp;
}

int main()
{

    return 0;
}