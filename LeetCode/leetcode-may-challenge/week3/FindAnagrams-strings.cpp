#include <bits/stdc++.h>
using namespace std;

//Type: Strings
//Approach: Maintaing two freq arrays fro string s and p.
//          Populate the arrays by reading the first len(p) chars
//          Maintain two pointers - one to leftmost end of the word and another to the rightmost
//          Keep incrementing the freq of character at righ ptr and decrementing for left ptr
//          If at any instance, the two freq arrays are equal, we have found an anagram.
//Complexity: O(N) time and O(N) space, N->len(S)

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> indices;

        if (s.length() < p.length())
        {
            return indices;
        }

        int plen = p.length();
        int slen = s.length();

        vector<int> count(26, 0);
        vector<int> sCount(26, 0);

        for (int i = 0; i < plen; i++)
        {
            count[p[i] - 'a']++;
            sCount[s[i] - 'a']++;
        }

        int left = 0;
        int right = plen - 1;

        while (right < slen)
        {
            if (count == sCount)
            {
                indices.push_back(left);
            }
            right++;
            if (right != slen)
            {
                sCount[s[right] - 'a'] += 1;
            }
            sCount[s[left] - 'a'] -= 1;
            left++;
        }

        return indices;
    }
};

bool zero(int arr[])
{
    return !(arr[0] || arr[1] || arr[2] || arr[3] || arr[4] || arr[5] || arr[6] || arr[7] || arr[8] || arr[9] ||
             arr[10] || arr[11] || arr[12] || arr[13] || arr[14] || arr[15] || arr[16] || arr[17] || arr[18] || arr[19] ||
             arr[20] || arr[21] || arr[22] || arr[23] || arr[24] || arr[25]);
}

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (p.size() > s.size())
            return vector<int>();

        int freq[26] = {0};
        for (int i = 0; i < p.size(); i++)
            freq[p[i] - 'a']++;

        for (int i = 0; i < p.size(); i++)
            freq[s[i] - 'a']--;

        int l = 0, r = p.size() - 1;
        vector<int> ans;
        while (r + 1 < s.size())
        {
            if (zero(freq))
                ans.push_back(l);
            freq[s[++r] - 'a']--;
            freq[s[l++] - 'a']++;
        }
        if (zero(freq))
            ans.push_back(l);

        return ans;
    }
};