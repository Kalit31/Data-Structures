#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;
        int n = path.length();
        int i = 0;

        while (i < n - 1)
        {
            int ind = path.find('/', i + 1);
            string sub;
            if (ind == -1)
                sub = path.substr(i);
            else
                sub = path.substr(i, ind - i);
            if (sub == "/..")
            {
                if (!st.empty())
                    st.pop();
            }
            else if (sub != "/." && sub != "/")
            {
                st.push(sub);
            }
            if (ind == -1)
                break;
            i = ind;
        }
        string res = "";
        stack<string> st2;
        while (!st.empty())
        {
            st2.push(st.top());
            st.pop();
        }
        while (!st2.empty())
        {
            res.append(st2.top());
            st2.pop();
        }
        if (res == "")
        {
            return "/";
        }
        return res;
    }
};