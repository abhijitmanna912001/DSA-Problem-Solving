#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void solve(string mapping[], string output, int idx, vector<string> &ans, string str)
    {
        if (idx >= str.length())
        {
            if (output.length() > 0)
                ans.push_back(output);
            return;
        }

        string temp = mapping[str[idx] - '0'];
        for (auto ch : temp)
        {
            output.push_back(ch);
            solve(mapping, output, idx + 1, ans, str);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        string mapping[] = {"", "", "abc", "def", "ghi",
                            "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string output = "";
        int idx = 0;
        vector<string> ans;
        solve(mapping, output, idx, ans, digits);
        return ans;
    }
};

int main()
{

    return 0;
}