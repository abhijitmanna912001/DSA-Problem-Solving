#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    string b;

private:
    void dfs(string word, vector<string> &seq)
    {
        if (word == b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int sz = word.size();
        int steps = mp[word];

        for (int i = 0; i < sz; i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (mp.find(word) != mp.end() && mp[word] + 1 == steps)
                {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        b = beginWord;
        q.push({beginWord});
        mp[beginWord] = 1;
        int sz = beginWord.size();
        st.erase(beginWord);
        while (!q.empty())
        {
            string word = q.front();
            int steps = mp[word];
            q.pop();

            if (word == endWord)
                break;

            for (int i = 0; i < sz; i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word))
                    {
                        q.push(word);
                        st.erase(word);
                        mp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }

        if (mp.find(endWord) != mp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;

        // M1 - Brute Force - BFS
        // unordered_set<string> st(wordList.begin(), wordList.end());
        // queue<vector<string>> q;
        // q.push({beginWord});
        // vector<string> usedOnLevel;
        // usedOnLevel.push_back(beginWord);
        // int level = 0;
        // vector<vector<string>> ans;
        // while (!q.empty())
        // {
        //     vector<string> vec = q.front();
        //     q.pop();
        //     if (vec.size() > level)
        //     {
        //         level++;
        //         for (auto it : usedOnLevel)
        //             st.erase(it);
        //     }

        //     string word = vec.back();
        //     if (word == endWord)
        //     {
        //         if (ans.size() == 0)
        //             ans.push_back(vec);
        //         else if (ans[0].size() == vec.size())
        //             ans.push_back(vec);
        //     }

        //     for (int i = 0; i < word.size(); i++)
        //     {
        //         char original = word[i];
        //         for (char c = 'a'; c <= 'z'; c++)
        //         {
        //             word[i] = c;
        //             if (st.count(word) > 0)
        //             {
        //                 vec.push_back(word);
        //                 q.push(vec);
        //                 usedOnLevel.push_back(word);
        //                 vec.pop_back();
        //             }
        //         }
        //         word[i] = original;
        //     }
        // }
        // return ans;
    }
};

int main()
{

    return 0;
}