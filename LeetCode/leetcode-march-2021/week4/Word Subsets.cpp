#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> wordSubsets(vector<string> &A, vector<string> &B)
    {
        vector<string> result;
        vector<int> subFreq(26, 0);

        for (string b : B)
        {
            vector<int> currFreq(26, 0);
            for (char ch : b)
            {
                currFreq[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                subFreq[i] = max(subFreq[i], currFreq[i]);
            }
        }

        for (string a : A)
        {
            vector<int> supFreq(26, 0);
            for (char ch : a)
            {
                supFreq[ch - 'a']++;
            }
            bool poss = true;
            for (int i = 0; i < 26; i++)
            {
                if (supFreq[i] < subFreq[i])
                {
                    poss = false;
                    break;
                }
            }
            if (poss)
                result.push_back(a);
        }

        return result;
    }
};