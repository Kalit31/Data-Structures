#include <bits/stdc++.h>
using namespace std;

//Type: Strings
//Approach: Compute the frequency of each character in the string
//          Now, traverse the string again. The first character with frequency 1 is the first unique char
//Complexity: O(L) time

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int result = INT_MAX;
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            int index = s.find(ch);
            if (index != string::npos && index == s.find_last_of(ch))
            {
                result = min(result, index);
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};

class Solution
{
public:
    int firstUniqChar(string s)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int charray[26] = {0};
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            charray[s[i] - 'a']++;
        }

        for (int i = 0; i < n; i++)
        {
            if (charray[s[i] - 'a'] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};