#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int stringNo;

    TrieNode(char ch) : data(ch), stringNo(-1)
    {
        for (int i = 0; i < 26; i++)
            children[i] = 0;
    }
};

class Trie
{
public:
    TrieNode *root;

    void insertUtil(TrieNode *root, string &word, int i, int &stringNo)
    {
        if (i >= word.size())
        {
            root->stringNo = stringNo;
            return;
        }

        int idx = word[i] - 'a';
        if (!root->children[idx])
            root->children[idx] = new TrieNode(word[i]);
        insertUtil(root->children[idx], word, i + 1, stringNo);
    }

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(string &word, int &stringNo)
    {
        insertUtil(root, word, 0, stringNo);
    }

    bool isPalindrome(string &s, int low, int high)
    {
        while (low <= high)
        {
            if (s[low] != s[high])
                return false;
            low++, high--;
        }
        return true;
    }

    void searchCase2(TrieNode *root, vector<int> &myPalindrome, string s)
    {
        if (root->stringNo != -1)
        {
            if (isPalindrome(s, 0, s.size() - 1))
                myPalindrome.push_back(root->stringNo);
        }

        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != 0)
            {
                s.push_back(i + 'a');
                searchCase2(root->children[i], myPalindrome, s);
                s.pop_back();
            }
        }
    }

    void search(string &word, vector<int> &myPalindrome)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';
            if (curr->stringNo != -1)
            {
                if (isPalindrome(word, i, word.size() - 1))
                    myPalindrome.push_back(curr->stringNo);
            }

            if (curr->children[idx])
                curr = curr->children[idx];
            else
                return;
        }

        searchCase2(curr, myPalindrome, "");
    }
};

class Solution
{
public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        vector<vector<int>> ans;
        Trie trie;
        for (int i = 0; i < words.size(); i++)
        {
            auto reversedWord = words[i];
            reverse(reversedWord.begin(), reversedWord.end());
            trie.insert(reversedWord, i);
        }

        for (int i = 0; i < words.size(); i++)
        {
            vector<int> myPalindrome;
            trie.search(words[i], myPalindrome);
            for (auto it : myPalindrome)
            {
                if (it != i)
                    ans.push_back({i, it});
            }
        }
        return ans;
    }
};


// For GFG Problem
// class TrieNode
// {
// public:
//     TrieNode *children[26];
//     vector<int> palindromePrefixes; // To store indices of strings that form palindromes with the current prefix
//     int stringNo;

//     TrieNode() : stringNo(-1)
//     {
//         for (int i = 0; i < 26; i++)
//         {
//             children[i] = nullptr;
//         }
//     }
// };

// class Trie
// {
// public:
//     TrieNode *root;

//     Trie()
//     {
//         root = new TrieNode();
//     }

//     // Helper function to check if a substring is a palindrome
//     bool isPalindrome(string &s, int left, int right)
//     {
//         while (left < right)
//         {
//             if (s[left] != s[right])
//                 return false;
//             left++;
//             right--;
//         }
//         return true;
//     }

//     // Helper function to insert a word in reverse, and store palindrome information
//     void insert(string &word, int idx)
//     {
//         TrieNode *node = root;
//         for (int i = word.size() - 1; i >= 0; i--)
//         {
//             int charIndex = word[i] - 'a';

//             // If the current prefix (remaining part) is a palindrome, store the index
//             if (isPalindrome(word, 0, i))
//             {
//                 node->palindromePrefixes.push_back(idx);
//             }

//             if (!node->children[charIndex])
//             {
//                 node->children[charIndex] = new TrieNode();
//             }
//             node = node->children[charIndex];
//         }
//         node->stringNo = idx;                    // Store the string index
//         node->palindromePrefixes.push_back(idx); // Even the whole word might be a palindrome
//     }

//     // Search for palindrome pairs in the Trie
//     bool search(string &word, int idx, string arr[], int N)
//     {
//         TrieNode *node = root;

//         // Step 1: Traverse the Trie
//         for (int i = 0; i < word.size(); i++)
//         {
//             if (node->stringNo != -1 && node->stringNo != idx && isPalindrome(word, i, word.size() - 1))
//             {
//                 return true; // We found a palindrome
//             }

//             int charIndex = word[i] - 'a';
//             if (!node->children[charIndex])
//             {
//                 return false; // No match found
//             }
//             node = node->children[charIndex];
//         }

//         // Step 2: Check remaining nodes for palindrome pairs
//         for (int palindromeIdx : node->palindromePrefixes)
//         {
//             if (palindromeIdx != idx)
//             {
//                 return true; // A valid palindrome pair found
//             }
//         }

//         return false;
//     }
// };

// class Solution
// {
// public:
//     bool palindromepair(int N, string arr[])
//     {
//         Trie trie;

//         // Insert reversed strings into the Trie
//         for (int i = 0; i < N; i++)
//         {
//             trie.insert(arr[i], i);
//         }

//         // Search for palindrome pairs
//         for (int i = 0; i < N; i++)
//         {
//             if (trie.search(arr[i], i, arr, N))
//             {
//                 return true; // A valid palindrome pair exists
//             }
//         }

//         return false; // No valid palindrome pair found
//     }
// };

int main()
{

    return 0;
}