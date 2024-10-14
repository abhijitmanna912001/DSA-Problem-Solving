#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    class TrieNode
    {
    public:
        char value;
        TrieNode *children[26];
        int childCount = 0;
        bool isTerminal;

        TrieNode(char val)
        {
            this->value = val;
            for (int i = 0; i < 26; i++)
            {
                children[i] = NULL;
            }
            this->isTerminal = false;
            this->childCount = 0;
        }
    };

    void insertWord(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        char ch = word[0];
        int idx = ch - 'a';
        TrieNode *child;
        if (root->children[idx] != NULL)
            child = root->children[idx];
        else
        {
            child = new TrieNode(ch);
            root->children[idx] = child;
            root->childCount++;
        }

        insertWord(child, word.substr(1));
    }

    void LCP(string &ans, TrieNode *root)
    {
        if (root->isTerminal == true)
            return;
        TrieNode *child;
        if (root->childCount == 1)
        {
            for (int i = 0; i < 26; i++)
            {
                if (root->children[i] != NULL)
                    child = root->children[i];
            }
            ans.push_back(child->value);
        }
        else
            return;
        LCP(ans, child);
    }

    string longestCommonPrefix(vector<string> &strs)
    {
        TrieNode *root = new TrieNode('-');
        for (auto str : strs)
            insertWord(root, str);
        string ans = "";
        LCP(ans, root);
        return ans;
    }
};

int main()
{

    return 0;
}