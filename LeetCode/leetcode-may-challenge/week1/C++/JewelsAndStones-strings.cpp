#include <bits/stdc++.h>
using namespace std;

//Type: Strings, Implementation
//Approach:
//Complexity: O(L1*L2) time

class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        int jewels = 0;
        for (int i = 0; i < S.length(); i++)
        {
            if (J.find(S[i]) != string::npos)
                jewels++;
        }
        return jewels;
    }
};

class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        int count = 0;
        for (size_t i = 0; i < J.size(); i++)
        {
            for (size_t j = 0; j < S.size(); j++)
            {
                if (J[i] == S[j])
                {
                    count++;
                }
            }
        }
        return count;
    }
};