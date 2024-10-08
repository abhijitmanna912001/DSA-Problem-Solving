#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> nodesBetweenCriticalPoints(ListNode *head)
{
    vector<int> ans = {-1, -1};
    ListNode *prev = head;
    if (!prev)
        return ans;
    ListNode *curr = head->next;
    if (!curr)
        return ans;
    ListNode *nxt = head->next->next;
    if (!nxt)
        return ans;
    int firstCP = -1, lastCP = -1;
    int minDis = INT_MAX;
    int i = 1;
    while (nxt)
    {
        bool isCP = ((curr->val > prev->val && curr->val > nxt->val) || (curr->val < prev->val && curr->val < nxt->val)) ? true : false;
        if (isCP && firstCP == -1)
        {
            firstCP = i;
            lastCP = i;
        }
        else if (isCP)
        {
            minDis = min(minDis, i - lastCP);
            lastCP = i;
        }
        ++i;
        prev = prev->next;
        curr = curr->next;
        nxt = nxt->next;
    }
    if (lastCP == firstCP)
        return ans;
    else
    {
        ans[0] = minDis;
        ans[1] = lastCP - firstCP;
    }
    return ans;
}

int main()
{

    return 0;
}