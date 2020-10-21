#include <bits/stdc++.h>
using namespace std;

//Type: Stacks, strings

//Approach: Implementation
//Complexity: O(N) time , O(N) space complexity

class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> parStack;
        stack<int> starStack;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                parStack.push(i);
            }
            else if (s[i] == '*')
            {
                starStack.push(i);
            }
            else
            {
                if (!parStack.empty())
                {
                    parStack.pop();
                }
                else if (!starStack.empty())
                {
                    starStack.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        while (!parStack.empty())
        {
            if (starStack.empty())
            {
                return false;
            }
            else if (parStack.top() < starStack.top())
            {
                parStack.pop();
                starStack.pop();
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};