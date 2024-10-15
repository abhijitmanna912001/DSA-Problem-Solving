#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution
{
public:
    Node *findIntersection(Node *head1, Node *head2)
    {
        unordered_map<int, int> mp;
        Node *curr = head2;

        while (curr)
        {
            mp[curr->data]++;
            curr = curr->next;
        }

        Node *IL = NULL;
        Node *it = NULL;
        curr = head1;

        while (curr)
        {
            if (mp.find(curr->data) != mp.end())
            {
                if (!IL)
                {
                    IL = curr;
                    it = IL;
                }
                else
                {
                    if (mp[curr->data] > 0)
                    {
                        it->next = curr;
                        it = it->next;
                        mp[curr->data]--;
                    }
                }
            }
            curr = curr->next;
        }

        if (it != NULL)
            it->next = NULL;
        return IL;
    }
};

int main()
{

    return 0;
}