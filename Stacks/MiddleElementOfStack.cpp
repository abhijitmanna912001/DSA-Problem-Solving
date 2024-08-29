#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &st, int &pos, int &ans)
{
    if (pos == 1)
    {
        ans = st.top();
        // for delete
        // st.pop();
        return;
    }

    pos--;
    int temp = st.top();
    st.pop();

    solve(st, pos, ans);
    st.push(temp);
}

int getMiddleElement(stack<int> &st)
{
    int size = st.size();
    int pos = 0;
    if (st.empty())
        return -1;
    else
    {

        if (size & 1)
            pos = size / 2 + 1;
        else
            pos = size / 2;
    }
    int ans = -1;
    solve(st, pos, ans);
    return ans;
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    int mid = getMiddleElement(st);
    cout << "Middle Element: " << mid << endl;
    return 0;
}