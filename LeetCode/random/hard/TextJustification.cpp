#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string build(vector<string> &t, int l, bool last)
    {
        int wordLen = 0;
        for (string s : t)
        {
            wordLen += s.length();
        }
        int space = l - wordLen;
        //cout<<"SPACE: "<<space<<endl;
        int num = t.size();
        //cout<<"NUM: "<<num<<endl;
        if (last || num == 1)
        {
            //cout<<"HERE"<<endl;
            string result = "";
            int len = 0;
            for (int i = 0; i < num; i++)
            {
                result += t[i];
                result += " ";
                len += t[i].size() + 1;
            }
            //cout<<"LEN:"<<len<<endl;
            result.pop_back();
            len--;
            for (; len < l; len++)
            {
                result += " ";
            }
            return result;
        }
        string result = "";
        if (space % (num - 1) == 0)
        {
            result = t[0];
            for (int i = 1; i <= (num - 1); i++)
            {
                for (int j = 1; j <= (space / (num - 1)); j++)
                {
                    result += " ";
                }
                result += t[i];
            }
        }
        else
        {
            int k = space / (num - 1);
            int x = space - k * (num - 1);
            int y = num - 1 - x;
            result = t[0];
            int j;
            for (j = 1; j <= x; j++)
            {
                for (int i = 1; i <= (k + 1); i++)
                {
                    result += " ";
                }
                result += t[j];
            }
            for (; j < num; j++)
            {
                for (int i = 1; i <= (k); i++)
                {
                    result += " ";
                }
                result += t[j];
            }
        }
        return result;
    }

    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> result;
        vector<string> temp;
        int n = words.size();
        int i = 0;
        while (i < n)
        {
            //cout<<"I: "<<i<<endl;
            int len = -1;
            while (i < n && len <= maxWidth)
            {
                len++;
                if (len + words[i].length() > maxWidth)
                {
                    break;
                }
                len += words[i].length();
                temp.push_back(words[i]);
                i++;
            }
            string t;
            if (i == n)
                t = build(temp, maxWidth, true);
            else
                t = build(temp, maxWidth, false);
            //cout<<"T: "<<t<<endl;
            result.push_back(t);
            temp.clear();
        }
        return result;
    }
};