#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int len1 = s.length(), len2 = t.length(), idx = 0;

        if (len1 < len2)
            return "";

        int ansIdx = -1, len = INT_MAX;
        unordered_map<char, int> sCount, tCount;

        for (char ch : t)
            tCount[ch]++;

        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            sCount[ch]++;

            if (sCount[ch] <= tCount[ch])
                count++;

            if (count == len2)
            {
                while (sCount[s[idx]] > tCount[s[idx]] || tCount[s[idx]] == 0)
                {
                    if (sCount[s[idx]] > tCount[s[idx]])
                        sCount[s[idx]]--;
                    idx++;
                }

                int windowLength = i - idx + 1;
                if (windowLength < len)
                {
                    len = windowLength;
                    ansIdx = idx;
                }
            }
        }

        if (ansIdx == -1)
            return "";
        else
            return s.substr(ansIdx, len);
    }
};

// GFG Problem Solution

class Solution
{
public:
    string minWindow(string &s1, string &s2)
    {
        int len1 = s1.length(), len2 = s2.length();

        int minLength = INT_MAX;
        string result = "";

        for (int i = 0; i < len1; i++)
        {
            if (s1[i] == s2[0])
            { // Start matching from the first character of s2
                int k = i, j = 0;

                // Move forward in s1 and s2 to check if s2 is a subsequence
                while (k < len1 && j < len2)
                {
                    if (s1[k] == s2[j])
                        j++;
                    k++;
                }

                // If s2 is fully matched
                if (j == len2)
                {
                    // Minimize the window by moving the start pointer
                    int end = k - 1;
                    int start = i;
                    while (start < end && s2.find(s1[start]) == string::npos)
                    {
                        start++;
                    }

                    // Update the result if a smaller window is found
                    if (end - start + 1 < minLength)
                    {
                        minLength = end - start + 1;
                        result = s1.substr(start, minLength);
                    }
                }
            }
        }

        return result;
    }
};

int main()
{

    return 0;
}