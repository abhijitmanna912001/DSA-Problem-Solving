#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // M2 -Top Down Approach
    vector<string> solveByMemo(string &s, unordered_map<string, bool> &dict, int i, unordered_map<int, vector<string>> &dp)
    {
        if (i == s.size())
            return {""};

        if (dp.find(i) != dp.end())
            return dp[i];

        vector<string> ans;
        string word;

        for (int j = i; j < s.size(); j++)
        {
            word.push_back(s[j]);
            if (dict.find(word) == dict.end())
                continue;

            auto right = solveByMemo(s, dict, j + 1, dp);
            for (auto eachRightPart : right)
            {
                string endPart;
                if (eachRightPart.size() > 0)
                    endPart = " " + eachRightPart;
                ans.push_back(word + endPart);
            }
        }
        dp[i] = ans;
        return dp[i];
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<string, bool> dict;
        unordered_map<int, vector<string>> dp(s.size() + 1);
        for (auto word : wordDict)
            dict[word] = 1;

        return solveByMemo(s, dict, 0, dp);
    }

    // M1 - Recursive Approach
    vector<string> solveByRecur(string &s, unordered_map<string, bool> &dict, int i)
    {
        if (i == s.size())
            return {""};

        vector<string> ans;
        string word;

        for (int j = i; j < s.size(); j++)
        {
            word.push_back(s[j]);
            if (dict.find(word) == dict.end())
                continue;

            auto right = solveByRecur(s, dict, j + 1);
            for (auto eachRightPart : right)
            {
                string endPart;
                if (eachRightPart.size() > 0)
                    endPart = " " + eachRightPart;
                ans.push_back(word + endPart);
            }
        }
        return ans;
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<string, bool> dict;
        for (auto word : wordDict)
            dict[word] = 1;

        return solveByRecur(s, dict, 0);
    }
};

int main()
{

    return 0;
}