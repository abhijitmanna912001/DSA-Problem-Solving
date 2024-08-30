#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int &x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();

    insertAtBottom(st, x);

    st.push(temp);
}

void reverseStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int temp = st.top();
    st.pop();

    reverseStack(st);
    insertAtBottom(st, temp);
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    int element = 400;
    insertAtBottom(st, element);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}