#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    // M3 - Using Set and dp
    bool solveByMemo(string &s, unordered_set<string> &wordSet, int start,
                     vector<int> &dp)
    {
        if (start == s.size())
            return true;

        if (dp[start] != -1)
            return dp[start];

        for (int len = 1; len <= s.size() - start; ++len)
        {
            string word = s.substr(start, len);
            if (wordSet.count(word) && solveByMemo(s, wordSet, start + len, dp))
            {
                return dp[start] = true;
            }
        }
        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return solveByMemo(s, wordSet, 0, dp);
    }
    
    // M2- Top Down Approach
    bool check(vector<string> &wordDict, string &s)
    {
        for (auto i : wordDict)
            if (s == i)
                return true;

        return false;
    }

    bool solveByTabul(string &s, vector<string> &wordDict, int start, vector<int> &dp)
    {
        for (int start = s.size() - 1; start >= 0; start--)
        {
            string word = "";
            bool flag = false;
            for (int i = start; i < s.size(); i++)
            {
                word += s[i];
                if (check(wordDict, word))
                    flag = flag || dp[i + 1];
            }
            dp[start] = flag;
        }

        return dp[0];
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> dp(s.size() + 1, true);
        return solveByTabul(s, wordDict, 0, dp);
    }

    // M2- Top Down Approach - TLE
    bool check(vector<string> &wordDict, string &s)
    {
        for (auto i : wordDict)
            if (s == i)
                return true;

        return false;
    }

    bool solveByMemo(string &s, vector<string> &wordDict, int start, vector<int> &dp)
    {
        if (start == s.size())
            return true;

        if (dp[start] != -1)
            return dp[start];

        string word = "";
        bool flag = false;
        for (int i = 0; i < s.size(); i++)
        {
            word += s[i];
            if (check(wordDict, word))
                flag = flag || solveByMemo(s, wordDict, i + 1, dp);
        }
        dp[start] = flag;
        return dp[start];
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> dp(s.size(), -1);
        return solveByMemo(s, wordDict, 0, dp);
    }

    // M1- Recursion Approach - TLE
    bool check(vector<string> &wordDict, string &s)
    {
        for (auto i : wordDict)
            if (s == i)
                return true;
        return false;
    }

    bool solveByRecur(string &s, vector<string> &wordDict, int start)
    {
        if (start == s.size())
            return true;

        string word = "";
        bool flag = false;
        for (int i = 0; i < s.size(); i++)
        {
            word += s[i];
            if (check(wordDict, word))
                flag = flag || solveByRecur(s, wordDict, i + 1);
        }
        return flag;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        return solveByRecur(s, wordDict, 0);
    }
};

int main()
{

    return 0;
}