#include <iostream>
#include <unordered_map>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m)
{
    unordered_map<int, int> mp;
    string ans = "Yes";
    for (int i = 0; i < n; i++)
        mp[a1[i]]++;
    for (int i = 0; i < m; i++)
    {
        if (mp.find(a2[i]) == mp.end())
        {
            ans = "No";
            break;
        }
        else
        {
            if (mp[a2[i]] > 0)
                mp[a2[i]]--;
            else
            {
                ans = "No";
                break;
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}