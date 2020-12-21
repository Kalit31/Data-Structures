#include <bits/stdc++.h>
using namespace std;

//Type: Strings
//Approach: Initialise the currChar with starting character and maintain the currLen = 1.
//          Start traversing the string, if it matches the last char, increment length,
//          else update the maxlen and set currLen back to 1 and update currChar.

class Solution
{
public:
    int maxPower(string s)
    {
        int n = s.size();
        int maxLen = 0;
        int currLen = 1;
        char currChar = s[0];
        for (int i = 1; i < n; i++)
        {
            if (currChar == s[i])
            {
                currLen++;
            }
            else
            {
                maxLen = max(maxLen, currLen);
                currLen = 1;
                currChar = s[i];
            }
        }
        maxLen = max(maxLen, currLen);
        return maxLen;
    }
};