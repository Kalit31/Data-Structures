#include <bits/stdc++.h>
using namespace std;

//Type: Strings, Implementation
//Approach: Maintain the frequency of the alphabets.
//          Traverse through the magazine string, incrementing the frequency of each character.
//          Now, traverse through the note string, decrementing the frequency of each character
//          Now, traverse the freq array. If at any point we find the value to be negative,
//          it means there are not enough charcters in the magazine string to build the note string.
//Complexity:  O(max(L1,L2)) time

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (magazine.length() < ransomNote.length())
            return false;
        int caps[26] = {0};
        for (char ch : ransomNote)
        {
            int index = magazine.find(ch, caps[ch - 'a']);
            if (index == string::npos)
                return false;
            caps[ch - 'a'] = index + 1;
        }
        return true;
    }
};

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int count[26] = {0};
        for (int i = 0; i < ransomNote.size(); i++)
        {
            count[ransomNote[i] - 'a']++;
        }
        for (int i = 0; i < magazine.size(); i++)
        {
            count[magazine[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (count[i] > 0)
            {
                return false;
            }
        }
        return true;
    }
};