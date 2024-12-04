#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int minCost(vector<int> &arr)
    {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            int val = arr[i];
            pq.push(val);
        }
        int cost = 0;
        while (pq.size() > 1)
        {
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            cost += top1 + top2;
            int sum = top1 + top2;
            pq.push(sum);
        }
        return cost;
    }
};

int main()
{

    return 0;
}