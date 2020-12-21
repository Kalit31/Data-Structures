#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeAtIndex(string S, int K)
    {
        long long int size = 0;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] >= '1' && S[i] <= '9')
            {
                size += (size) * ((int)(S[i] - '1'));
            }
            else
            {
                size++;
            }
        }

        string res = " ";

        for (int i = S.size() - 1; i >= 0; i--)
        {
            char ch = S[i];
            K = K % size;
            if (K == 0 && isalpha(ch))
            {
                string result;
                result.push_back(ch);
                return result;
            }
            if (isdigit(ch))
            {
                size /= (int)(ch - '0');
            }
            else
            {
                size--;
            }
        }

        return res;
    }
};