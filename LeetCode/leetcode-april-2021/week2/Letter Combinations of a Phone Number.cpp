#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findLetters(int n)
    {
        switch (n)
        {
        case 2:
            return "abc";
        case 3:
            return "def";
        case 4:
            return "ghi";
        case 5:
            return "jkl";
        case 6:
            return "mno";
        case 7:
            return "pqrs";
        case 8:
            return "tuv";
        case 9:
            return "wxyz";
        }
        return "";
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        if (digits == "")
            return result;
        result.push_back("");
        vector<string> tmp;

        for (char ch : digits)
        {
            tmp.clear();
            int digit = ch - '0';
            string str = findLetters(digit);
            for (string comb : result)
            {
                for (char c : str)
                {
                    string newComb = comb + c;
                    tmp.push_back(newComb);
                }
            }
            result = tmp;
        }

        return result;
    }
};