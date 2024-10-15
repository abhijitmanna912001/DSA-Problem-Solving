#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

// Method 1: Using Hashing and Priority Queue
// For GFG consider int,int map instead of string,int
class Solution1
{
public:
    class comp
    {
    public:
        bool operator()(pair<string, int> &a, pair<string, int> &b)
        {
            // For GFG
            //  return (a.second == b.second) ? (a.first < b.first) : (a.second < b.second);
            return (a.second == b.second) ? (a > b) : (a.second < b.second);
        }
    };

    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> mp;
        for (auto &i : words)
            mp[i]++;

        priority_queue<pair<string, int>, vector<pair<string, int>>, comp> pq;
        for (auto &i : mp)
            pq.push(i);

        vector<string> ans;
        while (!pq.empty() && k--)
        {
            auto &elem = pq.top();
            ans.push_back(elem.first);
            pq.pop();
        }
        return ans;
    }
};

// Method 2: Using Tries and Priority Queue
class Solution
{
public:
    class TrieNode
    {
    public:
        char data;
        TrieNode *children[26];
        bool isTerminal;
        int freq;

        TrieNode(char ch) : data(ch), isTerminal(false)
        {
            for (int i = 0; i < 26; i++)
                children[i] = 0;
            freq = 0;
        }
    };

    class comp
    {
    public:
        bool operator()(const pair<int, string> &a, const pair<int, string> &b)
        {
            return a.first == b.first ? a < b : a.first > b.first;
        }
    };

    class Trie
    {
    public:
        TrieNode *root;

        void insertUtil(TrieNode *root, string &word, int i)
        {
            if (i >= word.size())
            {
                root->isTerminal = true;
                root->freq++;
                return;
            }

            int idx = word[i] - 'a';
            if (!root->children[idx])
                root->children[idx] = new TrieNode(word[i]);
            insertUtil(root->children[idx], word, i + 1);
        }

        void traverseUtil(TrieNode *root, string &s, priority_queue<pair<int, string>, vector<pair<int, string>>, comp> &pq, int &k)
        {
            if (!root)
                return;
            if (root->isTerminal)
            {
                if (pq.size() < k)
                    pq.push({root->freq, s});
                else if (pq.size() == k && root->freq > pq.top().first)
                {
                    pq.pop();
                    pq.push({root->freq, s});
                }
            }

            for (int i = 0; i < 26; i++)
            {
                if (root->children[i])
                {
                    s.push_back(i + 'a');
                    traverseUtil(root->children[i], s, pq, k);
                    s.pop_back();
                }
            }
        }

        Trie()
        {
            root = new TrieNode('\0');
        }

        void insert(string word)
        {
            insertUtil(root, word, 0);
        }

        void traverse(priority_queue<pair<int, string>, vector<pair<int, string>>, comp> &pq, int k)
        {
            string s;
            traverseUtil(root, s, pq, k);
        }
    };

    vector<string> topKFrequent(vector<string> &words, int k)
    {
        Trie trie;
        vector<string> ans;
        for (auto word : words)
            trie.insert(word);

        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
        trie.traverse(pq, k);

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    return 0;
}