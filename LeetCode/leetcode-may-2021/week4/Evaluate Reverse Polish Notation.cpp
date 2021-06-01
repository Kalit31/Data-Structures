#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int get(stack<int> &st)
    {
        int ans = st.top();
        st.pop();
        return ans;
    }

    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int n1 = get(st);
                int n2 = get(st);
                if (tokens[i] == "+")
                {
                    st.push(n1 + n2);
                }
                else if (tokens[i] == "-")
                {
                    st.push(n2 - n1);
                }
                else if (tokens[i] == "*")
                {
                    st.push(n1 * n2);
                }
                else if (tokens[i] == "/")
                {
                    st.push(n2 / n1);
                }
            }
            else
            {
                int num = stoi(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};