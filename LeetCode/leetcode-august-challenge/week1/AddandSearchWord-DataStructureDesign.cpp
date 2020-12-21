#include <bits/stdc++.h>
using namespace std;

class WordDictionary
{
public:
    struct TrieNode
    {
        char val;
        int count;
        int endsHere;
        TrieNode *child[26];
    };
    TrieNode *root;

    TrieNode *getNode(int index)
    {
        TrieNode *newNode = new TrieNode;
        newNode->val = 'a' + index;
        newNode->count = newNode->endsHere = 0;
        for (int i = 0; i < 26; i++)
        {
            newNode->child[i] = NULL;
        }
        return newNode;
    }

    /** Initialize your data structure here. */
    WordDictionary()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        root = getNode('/' - 'a');
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        TrieNode *curr = root;
        int index;
        for (int i = 0; i < word.length(); i++)
        {
            index = word[i] - 'a';
            if (curr->child[index] == NULL)
            {
                curr->child[index] = getNode(index);
            }
            curr->child[index]->count += 1;
            curr = curr->child[index];
        }
        curr->endsHere += 1;
    }

    bool solve(string word, int ind, TrieNode *n)
    {
        if (ind == word.size())
        {
            return (n->endsHere);
        }
        char ch = word[ind];
        if (ch != '.')
        {
            if (n->child[ch - 'a'] == NULL)
            {
                return false;
            }
            return solve(word, ind + 1, n->child[ch - 'a']);
        }
        else
        {
            bool possible = false;
            for (int i = 0; i < 26; i++)
            {
                if (n->child[i] != NULL)
                {
                    possible = solve(word, ind + 1, n->child[i]);
                    if (possible)
                        break;
                }
            }
            return possible;
        }
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return solve(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */