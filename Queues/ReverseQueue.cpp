#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverseQueueRecur(queue<int> &q)
{
    if (q.empty())
        return;
    int ele = q.front();
    q.pop();
    reverseQueueRecur(q);
    q.push(ele);
}

void reverseQueue(queue<int> &q)
{
    stack<int> st;
    while (!q.empty())
    {
        int frontEle = q.front();
        q.pop();
        st.push(frontEle);
    }

    while (!st.empty())
    {
        int ele = st.top();
        st.pop();
        q.push(ele);
    }
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(50);
    q.push(60);

    reverseQueue(q);
    return 0;
}