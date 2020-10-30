#include <bits/stdc++.h>
using namespace std;

//Type: Strings
//Approach: Maintain a ptr to the string s.
//          Start traversing characters in string t.
//          If the character matches with the ptr to char in s, increment the ptr
//          Finally, check whether the ptr points to end of string s.
//          If yes, return true, else return false.
//Complexity: O(Length of string) time

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int ptr = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (s[ptr] == t[i])
            {
                ptr++;
                if (ptr == s.size())
                {
                    break;
                }
            }
        }
        return (ptr == s.size());
    }
};