#include <iostream>
#include <unordered_map>
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
    void sanitiseMap(ListNode *head, unordered_map<int, ListNode *> &mp, int currSum)
    {
        int temp = currSum;
        while (true)
        {
            temp += head->val;
            if (temp == currSum)
                break;
            mp.erase(temp);
            head = head->next;
        }
    }

    ListNode *removeZeroSumSublists(ListNode *head)
    {
        if (!head || (!head->next && head->val == 0))
            return 0;
        unordered_map<int, ListNode *> mp;
        auto it = head;
        int currSum = 0;
        while (it)
        {
            currSum += it->val;
            if (currSum == 0)
            {
                head = it->next;
                mp.clear();
            }
            else if (mp.find(currSum) != mp.end())
            {
                sanitiseMap(mp[currSum]->next, mp, currSum);
                mp[currSum]->next = it->next;
            }
            else
                mp[currSum] = it;
            it = it->next;
        }
        return head;
    }
};

int main()
{

    return 0;
}