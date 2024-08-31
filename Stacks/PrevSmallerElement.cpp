#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> leftSmaller(int n, int a[])
{
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < n; i++)
    {
        int curr = a[i];
        while (st.top() >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}

int main()
{

    return 0;
}