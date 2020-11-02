#include <bits/stdc++.h>
using namespace std;

//Type: Tries
//Approach: Insert all the words of dictionary into the trie.
//          Now, traverse through the entire board and check if a word be formed starting from the current cell.
//          The solve function first matches if the current node has the child of particular character.
//          If we reach the end of the trie word, we have found an acceptable word and insert it into our result.
//          Else we traverse in all the 4 directions from current cell.

class Solution
{
public:
    struct TrieNode
    {
        char val;
        TrieNode *child[26];
        int endsHere;
        string word;
    };

    TrieNode *getNode(int index)
    {
        TrieNode *newNode = new TrieNode;
        newNode->val = 'a' + index;
        newNode->endsHere = 0;
        newNode->word = "";
        for (int i = 0; i < 26; i++)
        {
            newNode->child[i] = NULL;
        }
        return newNode;
    }

    TrieNode *root;

    void insert(string s)
    {
        TrieNode *curr = root;
        int index, i = 0;
        while (s[i])
        {
            index = s[i] - 'a';
            if (curr->child[index] == NULL)
                curr->child[index] = getNode(s[i]);

            curr = curr->child[index];
            i += 1;
        }
        curr->endsHere += 1;
        curr->word = s;
    }

    void solve(vector<vector<char>> &board, int i, int j, vector<string> &result, TrieNode *curr)
    {
        int index = board[i][j] - 'a';
        if (board[i][j] == ' ' || curr->child[index] == NULL)
        {
            return;
        }
        curr = curr->child[index];
        if (curr->endsHere > 0)
        {
            result.push_back(curr->word);
            curr->endsHere = -1;
        }
        char ch = board[i][j];
        board[i][j] = ' ';
        if (i > 0)
            solve(board, i - 1, j, result, curr);
        if (i < board.size() - 1)
            solve(board, i + 1, j, result, curr);
        if (j > 0)
            solve(board, i, j - 1, result, curr);
        if (j < board[0].size() - 1)
            solve(board, i, j + 1, result, curr);
        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        root = getNode('/' - 'a');
        for (int i = 0; i < words.size(); i++)
        {
            insert(words[i]);
        }
        vector<string> result;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                solve(board, i, j, result, root);
            }
        }
        return result;
    }
};