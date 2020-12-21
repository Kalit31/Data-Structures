#include <bits/stdc++.h>
using namespace std;

class CombinationIterator
{
public:
    string s;
    int n;
    vector<string> list;
    int pos;
    CombinationIterator(string characters, int combinationLength)
    {
        s = characters;
        n = combinationLength;
        int len = s.size();
        for (int i = pow(2, len) - 1; i >= 1; i--)
        {
            int count = 0;
            int k = i;
            while (k)
            {
                if (k & 1)
                    count++;
                k = k >> 1;
            }
            if (count == n)
            {
                int t = i;
                string temp = "";
                int ind = s.size() - 1;
                while (t)
                {
                    if (t & 1)
                    {
                        temp = s[ind] + temp;
                    }
                    ind--;
                    t = t >> 1;
                }
                list.push_back(temp);
            }
        }
        pos = 0;
    }

    string next()
    {
        if (pos == list.size())
            return "";
        return list[pos++];
    }

    bool hasNext()
    {
        return pos != list.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */