#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> nextLargerNodes2(ListNode *head)
    {
        stack<pair<int, int>> st;
        vector<int> ans;
        int i = 0;

        while (head)
        {
            ans.push_back(0);
            while (!st.empty() && st.top().second < head->val)
            {
                auto top = st.top();
                st.pop();
                ans[top.first] = head->val;
            }
            st.push({i++, head->val});
            head = head->next;
        }
        return ans;
    }

    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> ll;
        while (head)
        {
            ll.push_back(head->val);
            head = head->next;
        }
        stack<int> st;
        // vector<int> ans(ll.size());

        for (int i = 0; i < ll.size(); i++)
        {
            while (!st.empty() && ll[i] > ll[st.top()])
            {
                int kids = st.top();
                st.pop();
                ll[kids] = ll[i];
            }
            st.push(i);
        }
        while (!st.empty())
        {
            ll[st.top()] = 0;
            st.pop();
        }

        ll[ll.size() - 1] = 0;
        return ll;
    }
};

int main()
{

    return 0;
}