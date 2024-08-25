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

ListNode *func(ListNode *head, int &n, int &ans)
{
    if (head == 0)
        return;
    func(head->next, n, ans);
    if (n == 0)
    {
        ans = head->val;
    }
    n--;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int ans = -1;
    return func(head, n, ans);
}
int getKthFromLast(Node *head, int k)
{
    Node *first = head;
    Node *second = head;

    // Move the first pointer `k` steps ahead
    for (int i = 0; i < k; ++i)
    {
        if (first == nullptr)
            return -1; // If k is greater than the number of nodes
        first = first->next;
    }

    // Move both pointers until the first pointer reaches the end
    while (first != nullptr)
    {
        first = first->next;
        second = second->next;
    }

    // Now, second pointer is at the k-th node from the end
    return (second != nullptr) ? second->data : -1;
}

int main()
{

    return 0;
}