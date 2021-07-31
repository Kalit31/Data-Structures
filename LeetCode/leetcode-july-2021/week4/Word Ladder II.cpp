#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> result;

        map<string, bool> mp;
        for (string x : wordList)
        {
            mp[x] = true;
        }

        queue<vector<string>> q;
        q.push({beginWord});
        map<string, bool> visited;
        visited[beginWord] = true;

        while (!q.empty())
        {
            int sz = q.size();
            for (auto it = visited.begin(); it != visited.end(); it++)
            {
                mp[it->first] = false;
            }
            while (sz--)
            {
                vector<string> curr = q.front();
                q.pop();
                if (!result.empty())
                {
                    if (curr.size() > result[0].size())
                    {
                        continue;
                    }
                }
                if (curr.back() == endWord)
                {
                    if (result.empty())
                    {
                        result.push_back(curr);
                    }
                    else
                    {
                        if (result[0].size() == curr.size())
                        {
                            result.push_back(curr);
                        }
                    }
                    continue;
                }
                string last = curr.back();

                for (int i = 0; i < last.size(); i++)
                {
                    char ch = last[i];
                    for (int j = 'a'; j <= 'z'; j++)
                    {
                        last[i] = j;
                        if (mp[last])
                        {
                            visited[last] = false;
                            vector<string> newCurr = curr;
                            newCurr.push_back(last);
                            q.push(newCurr);
                        }
                    }
                    last[i] = ch;
                }
            }
        }
        return result;
    }
};