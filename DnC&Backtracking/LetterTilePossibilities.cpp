#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &freq)
    {
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != 0)
            {
                ans++;
                freq[i]--;

                int recurAns = solve(freq);
                ans += recurAns;
                freq[i]++;
            }
        }
        return ans;
    }

    int numTilePossibilities(string tiles)
    {
        vector<int> freq(26, 0);
        for (auto ch : tiles)
            freq[ch - 'A']++;

        int ans = solve(freq);
        return ans;
    }
};

int main()
{

    return 0;
}