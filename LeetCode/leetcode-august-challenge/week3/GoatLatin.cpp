#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string toGoatLatin(string S)
    {
        stringstream ss(S);
        string s;
        int index = 1;
        string result = "";
        while (ss >> s)
        {
            string toAdd = "";
            for (int i = 1; i <= index; i++)
            {
                toAdd += "a";
            }
            index++;

            char ch = tolower(s[0]);

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                s = s + "ma" + toAdd + " ";
            }
            else
            {
                char temp = s[0];
                s.erase(s.begin());
                s = s + temp + "ma" + toAdd + " ";
            }
            result += s;
        }
        result.pop_back();
        return result;
    }
};