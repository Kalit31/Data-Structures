#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int transform = 0;
        if (beginWord == endWord)
        {
            return 0;
        }
        unordered_map<string, int> dict;

        for (auto x : wordList)
        {
            dict[x] = true;
        }

        queue<string> q;
        q.push(beginWord);
        unordered_map<string, int> vis;
        vis[beginWord] = 1;
        transform = 1;
        while (!q.empty())
        {
            int size = q.size();
            for (int k = 0; k < size; k++)
            {
                auto s = q.front();
                q.pop();
                if (s == endWord)
                {
                    return transform;
                }
                for (int i = 0; i < s.size(); i++)
                {
                    string orig = s;
                    for (int j = 0; j < 26; j++)
                    {
                        orig[i] = 'a' + j;
                        if (dict.find(orig) != dict.end() && vis.find(orig) == vis.end())
                        {
                            q.push(orig);
                            vis[orig] = 1;
                        }
                    }
                }
            }
            transform++;
        }
        return 0;
    }
};