#include <iostream>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[58];
    bool isTerminal;

    TrieNode(char ch) : data(ch), isTerminal(false)
    {
        for (int i = 0; i < 58; i++)
            children[i] = 0;
    }
};

class Trie
{
    TrieNode *root;

    void insertUtil(TrieNode *root, string &word, int i)
    {
        if (i >= word.size())
        {
            root->isTerminal = true;
            return;
        }

        int idx = word[i] - 'A';
        if (!root->children[idx])
            root->children[idx] = new TrieNode(word[i]);
        insertUtil(root->children[idx], word, i + 1);
    }

    bool searchUtil(TrieNode *root, string &word, int i)
    {
        if (i >= word.size())
            return root->isTerminal;
        int idx = word[i] - 'A';

        if (root->children[idx])
            return searchUtil(root->children[idx], word, i + 1);

        else if (islower(word[i]))
            return searchUtil(root, word, i + 1);

        return false;
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(string &word)
    {
        insertUtil(root, word, 0);
    }

    bool search(string &word)
    {
        return searchUtil(root, word, 0);
    }
};

class Solution
{
public:
    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        vector<bool> ans;
        Trie trie;
        trie.insert(pattern);
        for (auto query : queries)
            ans.push_back(trie.search(query));
        return ans;
    }
};

// For GFG Problem using Tries
// class TrieNode
// {
// public:
//     unordered_map<char, TrieNode *> children;
//     vector<string> words;
// };

// class Trie
// {
// private:
//     TrieNode *root;

// public:
//     Trie()
//     {
//         root = new TrieNode();
//     }

//     void insert(const string &word)
//     {
//         TrieNode *current = root;
//         for (char ch : word)
//         {
//             if (isupper(ch))
//             {
//                 if (!current->children[ch])
//                 {
//                     current->children[ch] = new TrieNode();
//                 }
//                 current = current->children[ch];
//             }
//         }
//         current->words.push_back(word);
//     }

//     void collectAllWords(TrieNode *node, vector<string> &result)
//     {
//         if (!node)
//             return;
//         result.insert(result.end(), node->words.begin(), node->words.end());
//         for (auto &child : node->children)
//         {
//             collectAllWords(child.second, result);
//         }
//     }

//     vector<string> search(const string &pattern)
//     {
//         TrieNode *current = root;
//         for (char ch : pattern)
//         {
//             if (current->children.find(ch) == current->children.end())
//             {
//                 return {};
//             }
//             current = current->children[ch];
//         }
//         vector<string> result;
//         collectAllWords(current, result);
//         return result;
//     }
// };

// class Solution
// {
// public:
//     vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern)
//     {
//         Trie trie;

//         for (const string &word : Dictionary)
//         {
//             trie.insert(word);
//         }

//         vector<string> result = trie.search(Pattern);

//         if (result.empty())
//         {
//             return {"-1"};
//         }

//         return result;
//     }
// };

// GFG String Manipulation using
// class Solution
// {
// public:
//     vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern)
//     {
//         vector<string> result;

//         // Iterate over each word in the dictionary
//         for (auto word : Dictionary)
//         {
//             string uppercaseLetters = "";

//             // Extract uppercase letters from the word
//             for (char ch : word)
//             {
//                 if (isupper(ch))
//                 {
//                     uppercaseLetters += ch;
//                 }
//             }

//             // Check if the uppercase letters match the pattern
//             if (uppercaseLetters.find(Pattern) == 0)
//             { // Pattern should be a prefix
//                 result.push_back(word);
//             }
//         }

//         // If no match found, return -1
//         if (result.empty())
//         {
//             return {"-1"};
//         }

//         return result;
//     }
// };

int main()
{

    return 0;
}