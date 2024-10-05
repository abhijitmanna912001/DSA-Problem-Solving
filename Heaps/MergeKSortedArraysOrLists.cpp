#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// GFG Problem
class Solution
{
public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        int i = 0;
        vector<int> nums(K * K);
        priority_queue<int, vector<int>, greater<int>> pq;
        for (i = 0; i < K; i++)
        {
            for (int j = 0; j < K; j++)
                pq.push(arr[i][j]);
        }
        i = 0;
        while (!pq.empty())
        {
            nums[i] = pq.top();
            pq.pop();
            i++;
        }
        return nums;
    }
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// LeetCode Problem
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // Custom comparator for ListNode pointers
        auto comp = [](ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        };

        // Min-heap (priority queue) to store ListNode pointers
        priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> pq(comp);

        // Insert the head of each list into the priority queue
        for (ListNode *list : lists)
        {
            if (list != nullptr)
            {
                pq.push(list);
            }
        }

        // Dummy node to make the result list
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;

        // Extract nodes from the heap and build the result list
        while (!pq.empty())
        {
            ListNode *curr = pq.top();
            pq.pop();

            // Add the current node to the merged list
            tail->next = curr;
            tail = curr;

            // If the current node has a next node, add it to the heap
            if (curr->next != nullptr)
            {
                pq.push(curr->next);
            }
        }

        // Return the merged list (dummy's next)
        return dummy->next;
    }
};

int main()
{

    return 0;
}