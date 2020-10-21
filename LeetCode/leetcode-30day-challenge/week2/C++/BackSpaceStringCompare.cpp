#include <bits/stdc++.h>
using namespace std;

//Type: Strings

//Approach: We shall store the new string in another variable.
//          Start traversing the string, if a non-# character is found, simply add to result.
//          Else, pop out the last character of the result if it is not empty, else continue.
//          Simply, form a new string for the other string.
//          Finally, compare the results of both the input strings.
//Complexity: O(N) time

class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {

        const char *sArr = S.c_str();
        const char *tArr = T.c_str();
        string newS = "";
        string newT = "";

        for (int i = 0; i < S.length(); i++)
        {
            if (sArr[i] == '#')
            {
                if (newS != "")
                {
                    newS.pop_back();
                }
            }
            else
            {
                newS += sArr[i];
            }
        }
        for (int i = 0; i < T.length(); i++)
        {
            if (tArr[i] == '#')
            {
                if (newT != "")
                {
                    newT.pop_back();
                }
            }
            else
            {
                newT += tArr[i];
            }
        }
        if (newS.compare(newT) == 0)
            return true;
        else
            return false;
    }
};