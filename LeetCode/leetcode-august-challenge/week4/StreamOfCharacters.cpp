#include <bits/stdc++.h>
using namespace std;

class StreamChecker
{
public:
    struct TrieNode
    {
        char val;
        bool endsHere;
        TrieNode *child[26];
    };
    TrieNode *root;

    TrieNode *getNode(int index)
    {
        TrieNode *newNode = new TrieNode;
        newNode->val = 'a' + index;
        newNode->endsHere = 0;
        for (int i = 0; i < 26; i++)
        {
            newNode->child[i] = NULL;
        }
        return newNode;
    }

    vector<char> untilNow;

    StreamChecker(vector<string> &words)
    {
        root = getNode('/' - 'a');
        for (string word : words)
        {
            insert(word);
        }
        untilNow.clear();
    }

    void insert(string word)
    {
        TrieNode *curr = root;
        int index;
        for (int i = word.length() - 1; i >= 0; i--)
        {
            index = word[i] - 'a';
            if (curr->child[index] == NULL)
            {
                curr->child[index] = getNode(index);
            }
            curr = curr->child[index];
        }
        curr->endsHere = true;
    }

    bool search(vector<char> &word)
    {
        TrieNode *curr = root;
        int index;
        for (int i = word.size() - 1; i >= 0; i--)
        {
            index = word[i] - 'a';
            if (curr->child[index] == NULL)
                return false;
            curr = curr->child[index];
            if (curr->endsHere)
            {
                return true;
            }
        }
        return false;
    }

    bool query(char letter)
    {
        untilNow.push_back(letter);
        return search(untilNow);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */