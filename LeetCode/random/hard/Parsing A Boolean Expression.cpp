#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool parseBoolExpr(string expression)
    {
        if (expression == "f")
        {
            return false;
        }
        else if (expression == "t")
        {
            return true;
        }
        char op = expression[0];
        if (op == '!')
        {
            string newExpr = expression.substr(2, expression.size() - 3);
            bool ans = parseBoolExpr(newExpr);
            return !ans;
        }
        else if (op == '|')
        {
            bool ans = false;
            string newExpr = expression.substr(2, expression.size() - 3);
            int cnt = 0;
            string currExpr = "";
            for (int i = 0; i < newExpr.size(); i++)
            {
                if (newExpr[i] == '(')
                {
                    cnt++;
                }
                else if (newExpr[i] == ')')
                {
                    cnt--;
                }
                if (cnt == 0 && newExpr[i] == ',')
                {
                    ans = ans | parseBoolExpr(currExpr);
                    currExpr = "";
                }
                else
                {
                    currExpr += newExpr[i];
                }
            }
            ans = ans | parseBoolExpr(currExpr);
            return ans;
        }
        else
        {
            //op is '&'
            bool ans = true;
            string newExpr = expression.substr(2, expression.size() - 3);
            int cnt = 0;
            string currExpr = "";
            for (int i = 0; i < newExpr.size(); i++)
            {
                if (newExpr[i] == '(')
                {
                    cnt++;
                }
                else if (newExpr[i] == ')')
                {
                    cnt--;
                }
                if (cnt == 0 && newExpr[i] == ',')
                {
                    ans = ans & parseBoolExpr(currExpr);
                    currExpr = "";
                }
                else
                {
                    currExpr += newExpr[i];
                }
            }
            ans = ans & parseBoolExpr(currExpr);
            return ans;
        }
        return false;
    }
};