#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string reverseWords(string &s)
    {
        string ans = "";
        string temp = "";
        bool word_started = false;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                if (word_started)
                {
                    if (!ans.empty())
                    {
                        ans += ' ';
                    }
                    ans += temp;
                    temp = "";
                    word_started = false;
                }
            }
            else
            {
                temp = s[i] + temp;
                word_started = true;
            }
        }

        if (word_started)
        {
            if (!ans.empty())
            {
                ans += ' ';
            }
            ans += temp;
        }

        return ans;
    }
};

int main()
{

    return 0;
}