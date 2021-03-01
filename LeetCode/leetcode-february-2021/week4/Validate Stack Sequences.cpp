#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int n = pushed.size();

        stack<int> st;

        int i = 0;
        int j = 0;

        while (true)
        {
            if (i == n)
            {
                break;
            }
            st.push(pushed[i++]);
            while (!st.empty() && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }
        return j == n;
    }
};