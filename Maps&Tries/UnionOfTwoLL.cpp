#include <iostream>
#include <map>
using namespace std;

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

class Solution
{
public:
    struct Node *makeUnion(struct Node *head1, struct Node *head2)
    {
        map<int, Node *> mp;
        Node *curr = head1;
        while (curr)
        {
            mp[curr->data] = curr;
            curr = curr->next;
        }

        curr = head2;
        while (curr)
        {
            mp[curr->data] = curr;
            curr = curr->next;
        }

        Node *UL = NULL;
        curr = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (!UL)
            {
                UL = it->second;
                curr = UL;
            }
            else
            {
                curr->next = it->second;
                curr = curr->next;
            }
        }
        curr->next = 0;
        return UL;
    }
};

int main()
{

    return 0;
}