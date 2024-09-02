#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid2(string s)
    {
        if (s[0] != 'a')
            return false;
        stack<char> st;
        for (char ch : s)
        {
            if (ch == 'a')
                st.push(ch);
            else if (ch == 'b')
            {
                if (!st.empty() && st.top() == 'a')
                    st.push('b');
                else
                    return false;
            }
            else
            {
                if (!st.empty() && st.top() == 'b')
                {
                    st.pop();
                    if (!st.empty() && st.top() == 'a')
                        st.pop();
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        return st.empty();
    }

    bool isValid(string s)
    {
        if (s.size() == 0)
            return true;

        int find = s.find("abc");
        if (find != string::npos)
        {
            string tleft = s.substr(0, find);
            string tright = s.substr(find + 3, s.size());
            return isValid(tleft + tright);
        }
        return false;
    }
};

int main()
{

    return 0;
}