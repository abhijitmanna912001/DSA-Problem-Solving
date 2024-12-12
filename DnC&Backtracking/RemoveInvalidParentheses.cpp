#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    void solve(string &s, unordered_set<string> &ans, int open, int close, int bal, int idx, string &output)
    {
        if (idx >= s.length())
        {
            if (open == 0 && close == 0 && bal == 0)
                ans.insert(output);
            return;
        }

        if (s[idx] != '(' && s[idx] != ')')
        {
            output.push_back(s[idx]);
            solve(s, ans, open, close, bal, idx + 1, output);
            output.pop_back();
        }
        else
        {
            if (s[idx] == '(')
            {
                if (open > 0)
                    solve(s, ans, open - 1, close, bal, idx + 1, output);
                output.push_back('(');
                solve(s, ans, open, close, bal + 1, idx + 1, output);
                output.pop_back();
            }
            else if (s[idx] == ')')
            {
                if (close > 0)
                    solve(s, ans, open, close - 1, bal, idx + 1, output);
                if (bal > 0)
                {
                    output.push_back(')');
                    solve(s, ans, open, close, bal - 1, idx + 1, output);
                    output.pop_back();
                }
            }
        }
    }

    vector<string> removeInvalidParentheses(string s)
    {
        unordered_set<string> ans;
        int invalidOpen = 0, invalidClose = 0, balance = 0, idx = 0;
        string output = "";

        for (auto ch : s)
        {
            if (ch == '(')
                invalidOpen++;
            else if (ch == ')')
            {
                if (invalidOpen > 0)
                    invalidOpen--;
                else
                    invalidClose++;
            }
        }

        solve(s, ans, invalidOpen, invalidClose, balance, idx, output);
        return vector<string>(ans.begin(), ans.end());
    }
};

int main()
{

    return 0;
}