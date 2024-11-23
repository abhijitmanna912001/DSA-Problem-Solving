#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isTerminal;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

// M2- DP Optimisation
class Solution
{
public:
    int dp[10001];
    class Trie
    {
    public:
        TrieNode *root;

        Trie() { root = new TrieNode(); }
        TrieNode *getRoot() { return root; }

        void insert(string &s)
        {
            int n = s.size();
            TrieNode *t = root;
            for (int i = 0; i < n; i++)
            {
                int k = s[i] - 'a';
                if (t->children[k] == NULL)
                    t->children[k] = new TrieNode();
                t = t->children[k];
            }
            t->isTerminal = true;
        }

        int search(string &s, int i, int n, int dp[])
        {
            if (i == n)
                return 0;
            if (dp[i] != -1)
                return dp[i];
            int ans = 1e6;
            TrieNode *h = root;
            for (int j = i; j < n; j++)
            {
                int k = s[j] - 'a';
                if (h->children[k] != NULL)
                {
                    ans = min(ans, 1 + search(s, j + 1, n, dp));
                    h = h->children[k];
                }
                else
                    break;
            }
            dp[i] = ans;
            return dp[i];
        }
    };

    int minValidStrings(vector<string> &words, string target)
    {
        Trie trie;
        for (auto i : words)
            trie.insert(i);
        int n = target.size();
        memset(dp, -1, sizeof(dp));
        int k = trie.search(target, 0, n, dp);
        if (k > 1e4)
            return -1;
        return k;
    }
};

// M1- Trie Based - TLE
class Solution
{
public:
    class Trie
    {
    public:
        TrieNode *root;

        Trie() { root = new TrieNode(); }
        TrieNode *getRoot() { return root; }

        void insert(string &s)
        {
            int n = s.size();
            TrieNode *t = root;
            for (int i = 0; i < n; i++)
            {
                int k = s[i] - 'a';
                if (t->children[k] == NULL)
                    t->children[k] = new TrieNode();
                t = t->children[k];
            }
            t->isTerminal = true;
        }

        int search(string &s, int i, int n)
        {
            if (i == n)
                return 0;
            int ans = 1e6;
            TrieNode *h = root;
            for (int j = i; j < n; j++)
            {
                int k = s[j] - 'a';
                if (h->children[k] != NULL)
                {
                    ans = min(ans, 1 + search(s, j + 1, n));
                    h = h->children[k];
                }
                else
                    break;
            }
            return ans;
        }
    };

    int minValidStrings(vector<string> &words, string target)
    {
        Trie trie;
        for (auto i : words)
            trie.insert(i);
        int n = target.size();
        int k = trie.search(target, 0, n);
        if (k > 1e4)
            return -1;
        return k;
    }
};

int main()
{
    
    return 0;
}