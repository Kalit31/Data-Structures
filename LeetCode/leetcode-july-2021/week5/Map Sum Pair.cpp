#include <bits/stdc++.h>
using namespace std;

class MapSum
{
public:
    struct TrieNode
    {
        char ch;
        int val;
        TrieNode *child[26];
    };
    TrieNode *root;

    TrieNode *getNode(int index)
    {
        TrieNode *newNode = new TrieNode;
        newNode->ch = 'a' + index;
        newNode->val = 0;
        for (int i = 0; i < 26; i++)
        {
            newNode->child[i] = NULL;
        }
        return newNode;
    }
    map<string, int> mp;
    /** Initialize your data structure here. */
    MapSum()
    {
        root = getNode('/' - 'a');
    }

    void insert(string key, int val)
    {
        int overrideVal = mp[key];
        mp[key] = val;
        TrieNode *curr = root;
        for (int i = 0; i < key.size(); i++)
        {
            int idx = key[i] - 'a';
            if (curr->child[idx] == NULL)
            {
                curr->child[idx] = getNode(idx);
            }
            curr->child[idx]->val -= overrideVal;
            curr->child[idx]->val += val;
            curr = curr->child[idx];
        }
    }

    int sum(string prefix)
    {
        int ans = 0;
        TrieNode *curr = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            int idx = prefix[i] - 'a';
            if (curr->child[idx] == NULL)
            {
                return 0;
            }
            ans = curr->child[idx]->val;
            curr = curr->child[idx];
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */