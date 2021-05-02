#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        if (bound == 0 || bound == 1)
        {
            return vector<int>();
        }

        if (x == 1 && y == 1)
        {
            if (bound >= 2)
            {
                return {2};
            }
            else
            {
                return vector<int>();
            }
        }
        else if (x == 1 || y == 1)
        {
            if (y == 1)
            {
                swap(x, y);
            }
            int curr = 1;
            int num2 = 0;
            while (curr * y <= bound)
            {
                curr = curr * y;
                num2++;
            }
            set<int> taken;
            vector<int> result;
            for (int i = 0; i <= num2; i++)
            {
                int num = pow(y, i);
                if (num + 1 > bound)
                {
                    break;
                }
                if (taken.find(num + 1) == taken.end())
                {
                    result.push_back(num + 1);
                    taken.insert(num + 1);
                }
            }
            return result;
        }

        int num1 = 0;
        int curr = 1;
        while (curr * x <= bound)
        {
            curr = curr * x;
            num1++;
        }
        curr = 1;
        int num2 = 0;
        while (curr * y <= bound)
        {
            curr = curr * y;
            num2++;
        }
        set<int> taken;
        vector<int> result;
        for (int i = 0; i <= num1; i++)
        {
            for (int j = 0; j <= num2; j++)
            {
                int num = pow(x, i) + pow(y, j);
                if (num > bound)
                {
                    break;
                }
                if (taken.find(num) == taken.end())
                {
                    result.push_back(num);
                    taken.insert(num);
                }
            }
        }

        return result;
    }
};