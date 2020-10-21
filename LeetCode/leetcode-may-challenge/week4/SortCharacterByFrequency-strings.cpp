#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        vector<pair<int, char>> count(123, {0, 0});

        for (int i = 0; i < s.length(); i++)
        {
            count[s[i]] = {count[s[i]].first + 1, s[i]};
        }

        sort(count.begin(), count.end());

        string result = "";
        for (auto it = count.begin(); it != count.end(); it++)
        {
            result = string(it->first, it->second) + result;
        }

        return result;
    }
};

class Solution
{
public:
    string frequencySort(string s)
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(0);

        unordered_map<char, int> m;
        string result;
        for (auto i : s)
            m[i]++;
        priority_queue<pair<int, char>> q;
        for (auto a : m)
        {
            q.push({a.second, a.first});
        }
        while (!q.empty())
        {
            auto t = q.top();
            q.pop();
            result.append(t.first, t.second);
        }
        return result;
    }
};