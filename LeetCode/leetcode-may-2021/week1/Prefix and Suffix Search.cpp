#include <bits/stdc++.h>
using namespace std;

class WordFilter
{
public:
    struct TrieNode
    {
        TrieNode *child[27];
        int index;
    };
    TrieNode *root;

    TrieNode *getNode()
    {
        TrieNode *newNode = new TrieNode;
        for (int i = 0; i < 27; i++)
        {
            newNode->child[i] = NULL;
        }
        return newNode;
    }

    void insert(string word, int ind)
    {
        string newWord = word + "$";
        // cout<<newWord<<endl;
        for (int i = 0; i < newWord.size(); i++)
        {
            TrieNode *curr = root;
            curr->index = ind;
            //  string add = "";
            for (int j = i; j < 2 * newWord.size() - 1; j++)
            {
                char currChar = newWord[j % newWord.size()];
                // cout<<"CH: "<<currChar<<endl;
                //                                add += currChar;

                int index = currChar - 'a';
                if (currChar == '$')
                {
                    index = 26;
                }
                if (curr->child[index] == NULL)
                {
                    curr->child[index] = getNode();
                }
                curr = curr->child[index];
                curr->index = ind;
            }
            // cout<<add<<endl;
        }
    }

    WordFilter(vector<string> &words)
    {
        root = getNode();
        for (int i = 0; i < words.size(); i++)
        {
            insert(words[i], i);
        }
    }

    int f(string prefix, string suffix)
    {
        string toSearch = suffix + "$" + prefix;
        // cout<<"SEARCH: "<<toSearch<<endl;
        TrieNode *curr = root;
        int index;
        for (int i = 0; i < toSearch.size(); i++)
        {
            char currChar = toSearch[i];
            index = currChar - 'a';
            if (currChar == '$')
            {
                index = 26;
            }
            if (curr->child[index] == NULL)
            {
                return -1;
            }
            curr = curr->child[index];
        }
        return curr->index;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */