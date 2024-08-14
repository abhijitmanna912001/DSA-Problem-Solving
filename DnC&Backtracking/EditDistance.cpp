#include <iostream>
using namespace std;

int solve(string &a, string &b, int i, int j)
{
    if (i >= a.length())
        return b.length() - j;
    if (j >= b.length())
        return a.length() - i;
    int ans = 0;
    if (a[i] == b[j])
        ans = 0 + solve(a, b, i + 1, j + 1);
    else
    {
        // insert
        int option1 = 1 + solve(a, b, i, j + 1);
        // remove
        int option2 = 1 + solve(a, b, i + 1, j);
        // replace
        int option3 = 1 + solve(a, b, i + 1, j + 1);
        ans = min(option1, min(option2, option3));
    }
    return ans;
}

int minDistance(string word1, string word2)
{
    int i = 0, j = 0;
    int ans = solve(word1, word2, i, j);
    return ans;
}

int main()
{

    return 0;
}