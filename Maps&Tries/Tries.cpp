#include <iostream>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char value;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char val)
    {
        this->value = val;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
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
    }

    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode *root, string word)
{
    if (word.length() == 0)
        return root->isTerminal;

    char ch = word[0];
    int idx = ch - 'a';
    TrieNode *child;

    if (root->children[idx] != NULL)
        child = root->children[idx];
    else
        return false;

    bool recursionAns = searchWord(child, word.substr(1));
    return recursionAns;
}

void deleteWord(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        root->isTerminal = false;
        return;
    }

    char ch = word[0];
    int idx = ch - 'a';
    TrieNode *child;

    if (root->children[idx] != NULL)
        child = root->children[idx];
    else
        return;

    deleteWord(child, word.substr(1));
}

void storeString(TrieNode *root, vector<string> &ans, string &input, string &prefix)
{
    if (root->isTerminal == true)
        ans.push_back(prefix + input);

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        int idx = ch - 'a';
        TrieNode *next = root->children[idx];
        if (next != NULL)
        {
            input.push_back(ch);
            storeString(next, ans, input, prefix);
            input.pop_back();
        }
    }
}

void findPrefixString(TrieNode *root, string input, vector<string> &ans, string &prefix)
{
    if (input.length() == 0)
    {
        TrieNode *lastchar = root;
        storeString(root, ans, input, prefix);
        return;
    }

    char ch = input[0];
    int idx = ch - 'a';
    TrieNode *child;
    if (root->children[idx] != NULL)
        child = root->children[idx];
    else
        return;
    findPrefixString(child, input.substr(1), ans, prefix);
}

vector<vector<string>> getSuggestions(TrieNode *root, string input)
{
    vector<vector<string>> ans;
    TrieNode *prev = root;
    string inputHelper = "";
    for (int i = 0; i < input.length(); i++)
    {
        char lastChar = input[i];
        int idx = lastChar - 'a';
        TrieNode *curr = prev->children[idx];

        if (curr == NULL)
            break;
        else
        {
            vector<string> belowAns;
            inputHelper.push_back(lastChar);
            string dummy = "";
            storeString(curr, belowAns, inputHelper, dummy);
            ans.push_back(belowAns);
        }
        prev = curr;
    }
    return ans;
}

int main()
{
    TrieNode *root = new TrieNode('-');

    insertWord(root, "cater");
    insertWord(root, "care");
    insertWord(root, "com");
    insertWord(root, "loved");
    insertWord(root, "load");
    insertWord(root, "bat");
    insertWord(root, "cat");
    insertWord(root, "car");
    insertWord(root, "lov");

    vector<vector<string>> ans = getSuggestions(root, "loa");
    for (int i = 0; i < ans.size(); i++)
    {
        cout << i << "->";
        for (auto str : ans[i])
        {
            cout << str << ", ";
        }
        cout << endl;
    }

    // string input = "c";
    // string prefix = input;
    // vector<string> ans;
    // findPrefixString(root, input, ans, prefix);
    // for (auto i : ans)
    //     cout << i << " ";
    // cout << endl;

    // cout << "Insertion Done" << endl;

    // if (searchWord(root, "loved"))
    //     cout << "Found" << endl;
    // else
    //     cout << "Not Found" << endl;

    // deleteWord(root, "loved");

    // if (searchWord(root, "loved"))
    //     cout << "Found" << endl;
    // else
    //     cout << "Not Found" << endl;

    return 0;
}