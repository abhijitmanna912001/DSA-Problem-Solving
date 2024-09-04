#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<char> st;
        int ans = 0;
        for (auto ch : s)
        {
            if (ch == '(')
            {
                ans++;
                st.push(ch);
            }
            else
            {
                if (!st.empty())
                {
                    st.pop();
                    ans--;
                }
                else
                    ans++;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}