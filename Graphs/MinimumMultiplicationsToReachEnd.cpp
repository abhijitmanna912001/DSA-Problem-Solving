#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        queue<int> q;
        int MOD = 100000;
        vector<int> ans(MOD, -1);
        ans[start] = 0;
        q.push(start);

        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            if (front == end)
                return ans[end];
            for (auto it : arr)
            {
                int newNode = (front * it) % MOD;
                if (ans[newNode] == -1)
                {
                    ans[newNode] = ans[front] + 1;
                    q.push(newNode);
                }
            }
        }
        return -1;
    }
};

int main()
{

    return 0;
}