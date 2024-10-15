#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch) : data(ch), isTerminal(false)
    {
        for (int i = 0; i < 26; i++)
            children[i] = 0;
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
            return;
        }

        int idx = word[i] - 'a';
        if (!root->children[idx])
            root->children[idx] = new TrieNode(word[i]);
        insertUtil(root->children[idx], word, i + 1);
    }

    bool searchUtil(TrieNode *root, string &word, int i)
    {
        if (i >= word.size())
            return root->isTerminal;
        int idx = word[i] - 'a';

        if (root->children[idx])
            return searchUtil(root->children[idx], word, i + 1);
        return false;
    }

    bool startsWithUtil(TrieNode *root, string &word, int i)
    {
        if (i >= word.size())
            return true;

        int idx = word[i] - 'a';
        if (root->children[idx])
            return startsWithUtil(root->children[idx], word, i + 1);
        return false;
    }

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(string word)
    {
        insertUtil(root, word, 0);
    }

    bool search(string word)
    {
        return searchUtil(root, word, 0);
    }

    bool startsWith(string prefix)
    {
        return startsWithUtil(root, prefix, 0);
    }
};

int main()
{

    return 0;
}