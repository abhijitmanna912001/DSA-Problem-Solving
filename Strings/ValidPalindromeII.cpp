#include <iostream>
using namespace std;

bool checkPalindrome(string s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        else
        {
            i++;
            j--;
        }
    }
    return true;
}

bool validPalindrome(string s)
{
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            bool ans1 = checkPalindrome(s, i + 1, j);
            bool ans2 = checkPalindrome(s, i, j - 1);
            return ans1 || ans2;
        }
    }
    return true;
}

int main()
{

    return 0;
}