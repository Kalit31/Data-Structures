#include <bits/stdc++.h>
using namespace std;

//Type: Strings, Heaps
//Approach: Store the frequency of each character in a map.
//          Maintain a max heap whose each element is (freq of char,char)
//          Start popping out the elements and add them to the final result.
//Complexity: O(NLgN) time

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

class Solution
{
public:
    struct myComp
    {
        bool operator()(const pair<char, int> &p1, const pair<char, int> &p2)
        {
            return p1.second < p2.second;
        }
    };

    string frequencySort(string s)
    {
        unordered_map<char, int> m;

        for (int i = 0; i < s.length(); i++)
        {
            m[s[i]]++;
        }

        vector<pair<char, int>> count;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            count.push_back({it->first, it->second});
        }
        sort(count.begin(), count.end(), myComp());

        string result = "";
        for (auto it = count.begin(); it != count.end(); it++)
        {
            result = string(it->second, it->first) + result;
        }

        return result;
    }
};