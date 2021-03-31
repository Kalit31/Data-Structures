#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {

        set<string> uniq;
        vector<string> s;

        for (string word : words)
        {
            if (uniq.find(word) == uniq.end())
            {
                s.push_back(word);
                uniq.insert(word);
            }
        }

        set<string> unique;

        int n = s.size();

        for (string word : s)
        {
            for (int len = 1; len < word.size(); len++)
            {
                uniq.erase(word.substr(len));
            }
        }

        int len = 0;
        for (auto it = uniq.begin(); it != uniq.end(); it++)
        {
            len += (*it).size() + 1;
        }
        return len;
    }
};

// TLE Solution: O(N*N*7)
class Solution
{
public:
    bool isPart(string a, string b)
    {
        int n = a.size();
        int m = b.size();
        if (n < m)
        {
            return false;
        }

        int i = n - 1;
        int j = m - 1;

        while (j >= 0)
        {
            if (a[i] != b[j])
            {
                return false;
            }
            i--;
            j--;
        }
        return true;
    }

    int minimumLengthEncoding(vector<string> &words)
    {

        set<string> uniq;
        vector<string> s;

        for (string word : words)
        {
            if (uniq.find(word) == uniq.end())
            {
                s.push_back(word);
                uniq.insert(word);
            }
        }

        set<string> unique;

        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            bool part = false;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                if (isPart(s[j], s[i]))
                {
                    part = true;
                    break;
                }
            }
            if (!part)
            {
                unique.insert(s[i]);
            }
        }

        int len = 0;
        for (auto it = uniq.begin(); it != uniq.end(); it++)
        {
            len += (*it).size() + 1;
        }
        return len;
    }
};
