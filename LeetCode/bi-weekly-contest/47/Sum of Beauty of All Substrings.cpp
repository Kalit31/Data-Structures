#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int beautySum(string s)
    {
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> freq(26, 0);
            multiset<int> minFreq;
            multiset<int, greater<int>> maxFreq;
            for (int j = i; j < n; j++)
            {
                char ch = s[j];
                auto it1 = minFreq.find(freq[ch - 'a']);
                if (it1 != minFreq.end())
                    minFreq.erase(it1);
                auto it2 = maxFreq.find(freq[ch - 'a']);
                if (it2 != maxFreq.end())
                    maxFreq.erase(it2);
                freq[ch - 'a']++;
                minFreq.insert(freq[ch - 'a']);
                maxFreq.insert(freq[ch - 'a']);
                sum += (*maxFreq.begin()) - (*minFreq.begin());
            }
        }
        return sum;
    }
};