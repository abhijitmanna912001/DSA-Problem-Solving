#include <iostream>
#include <vector>
using namespace std;

void getSubsequence(string str)
{
    int n = str.length();
    vector<string> ans;
    for (int num = 0; num < (1 << n); num++)
    {
        string temp = "";
        for (int i = 0; i < n; i++)
        {
            char ch = str[i];
            if (num & (1 << i))
                temp.push_back(ch);
        }
        ans.push_back(temp);
    }

    cout << "printing the subsequences: " << endl;
    for (auto i : ans)
    {
        cout << i << endl;
    }
}

int main()
{
    string str = "abc";
    getSubsequence(str);
    return 0;
}