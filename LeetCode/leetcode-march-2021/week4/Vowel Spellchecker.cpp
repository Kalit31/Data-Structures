#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string ToLower(string s)
    {
        for (int i = 0; i < s.size(); i++)
            s[i] = tolower(s[i]);

        return s;
    }

    string removeVowels(string s)
    {
        s = ToLower(s);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                s[i] = '#';
        }
        return s;
    }

    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        int n = queries.size();
        vector<string> ans(n);

        unordered_set<string> dict;
        for (string word : wordlist)
        {
            dict.insert(word);
        }
        unordered_map<string, string> lower;
        for (string word : wordlist)
        {
            string lowerWord = ToLower(word);
            if (lower.find(lowerWord) == lower.end())
                lower[lowerWord] = word;
        }
        unordered_map<string, string> noVowels;
        for (string word : wordlist)
        {
            string withoutVowels = removeVowels(word);
            if (noVowels.find(withoutVowels) == noVowels.end())
                noVowels[withoutVowels] = word;
        }

        for (int i = 0; i < n; i++)
        {
            string curr = queries[i];
            if (dict.find(curr) != dict.end())
            {
                ans[i] = curr;
            }
            else
            {
                string lowerCurr = ToLower(curr);
                if (lower.find(lowerCurr) != lower.end())
                {
                    ans[i] = lower[lowerCurr];
                }
                else
                {
                    string withoutVowels = removeVowels(curr);
                    if (noVowels.find(withoutVowels) != noVowels.end())
                    {
                        ans[i] = noVowels[withoutVowels];
                    }
                    else
                    {
                        ans[i] = "";
                    }
                }
            }
        }
        return ans;
    }
};