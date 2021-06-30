#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string removeDuplicates(string S)
    {
        stack<char> st;
        st.push(S[0]);
        for (int i = 1; i < S.length(); i++)
        {
            if (!st.empty() && st.top() == S[i])
            {
                while (!st.empty() && st.top() == S[i])
                {
                    st.pop();
                }
            }
            else
            {
                st.push(S[i]);
            }
        }
        string result;
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

class Solution {
public:
    string removeDuplicates(string s) {
        int slow = 0, fast = 0;
        for(fast = 0; fast < s.length(); fast++) {
            if(slow == 0 || s.at(slow - 1) != s.at(fast))
                s[slow++] = s[fast];
            else
                slow--;
        }
        return s.substr(0, slow);
    }
};
