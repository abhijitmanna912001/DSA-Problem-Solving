#include <iostream>
#include <vector>
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

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(string word)
    {
        insertUtil(root, word, 0);
    }

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

    int search(string word)
    {
        return searchUtil(root, word, 0);
    }

    int searchUtil(TrieNode *root, string &word, int i)
    {
        if (root->isTerminal) 
            return i;
        if (i >= word.size()) 
            return -1;

        int idx = word[i] - 'a';
        if (root->children[idx])
            return searchUtil(root->children[idx], word, i + 1);
        return -1;
    }
};

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        Trie trie;

        for (auto &root : dictionary)
            trie.insert(root);

        string ans;
        int start = 0, end = 0;

        while (end <= sentence.size())
        {
            if (end == sentence.size() || sentence[end] == ' ')
            {
                string word = sentence.substr(start, end - start);
                int trieMatchIdx = trie.search(word);

                if (trieMatchIdx != -1)
                    ans += word.substr(0, trieMatchIdx);
                else
                    ans += word;

                if (end != sentence.size())
                    ans += " ";

                start = end + 1;
            }
            end++;
        }

        return ans;
    }
};

int main()
{

    return 0;
}