#include <bits/stdc++.h>
using namespace std;

//Type: Stacks
//Approach: The basic idea is that the number on closer to the MSB
//          more weightage than the number far from MSB.
//          We will have to maintain digits in ascending order from the MSB.
//          This will produce the least possible number.
//Complexity: O(N) time and O(N) space

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (num.length() == k)
            return "0";
        stack<char> numStack;
        int i = 0;
        while (i < num.size())
        {
            while (k > 0 && !numStack.empty() && numStack.top() > num[i])
            {
                numStack.pop();
                k--;
            }
            numStack.push(num[i]);
            i++;
        }

        while (!numStack.empty() && k > 0)
        {
            numStack.pop();
            k--;
        }

        string result = "";

        while (!numStack.empty())
        {
            char current = numStack.top();
            numStack.pop();
            result.append(1, current);
        }

        reverse(result.begin(), result.end());

        while (result.size() > 1 && result[0] == '0')
        {
            result.erase(result.begin());
        }

        return result;
    }
};
