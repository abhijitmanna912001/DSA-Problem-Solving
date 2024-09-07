#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverseFirstK(queue<int> &q, int k)
{
    stack<int> st;
    int n = q.size();
    if (k > n || k == 0)
        return;

    for (int i = 0; i < k; i++)
    {
        int temp = q.front();
        q.pop();
        st.push(temp);
    }
    while (!st.empty())
    {
        int temp = st.top();
        st.pop();
        q.push(temp);
    }
    for (int i = 0; i < n - k; i++)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}

int main()
{

    return 0;
}