#include <bits/stdc++.h>
using namespace std;

//Type: Strings
//Approach: Maintaing two freq arrays fro string s and p.
//          Populate the arrays by reading the first len(p) chars
//          Maintain two pointers - one to leftmost end of the word and another to the rightmost
//          Keep incrementing the freq of character at righ ptr and decrementing for left ptr
//          If at any instance, the two freq arrays are equal, we have found a permutation.
//Complexity: O(N) time and O(N) space, N->len(S)

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {

        if (s2.length() < s1.length())
        {
            return false;
        }

        int s1len = s1.length();
        int s2len = s2.length();

        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        for (int i = 0; i < s1len; i++)
        {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        int left = 0;
        int right = s1len - 1;

        while (right < s2len)
        {
            if (s1Count == s2Count)
            {
                return true;
            }
            right++;
            if (right != s2len)
            {
                s2Count[s2[right] - 'a'] += 1;
            }
            s2Count[s2[left] - 'a'] -= 1;
            left++;
        }
        return false;
    }
};