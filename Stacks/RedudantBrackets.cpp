#include <iostream>
#include <stack>
using namespace std;

bool checkRedudant(string &str)
{
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            st.push(ch);
        else if (ch == ')')
        {
            int operatorCount = 0;
            while (!st.empty() && st.top() != '(')
            {
                char temp = st.top();
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
                    operatorCount++;
                st.pop();
            }
            st.pop();
            if (operatorCount == 0)
                return true;
        }
    }
    return false;
}

int main()
{
    string str = "((a+b)*(c+d))";
    bool ans = checkRedudant(str);

    if (ans == true)
    {
        cout << "Redudant Brackets Present" << endl;
    }
    else
    {
        cout << "No Redudant Brackets Present" << endl;
    }

    return 0;
}