#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char getRoman(int r)
    {
        switch (r)
        {
        case 1000:
            return 'M';
        case 500:
            return 'D';
        case 100:
            return 'C';
        case 50:
            return 'L';
        case 10:
            return 'X';
        case 5:
            return 'V';
        case 1:
            return 'I';
        }
        return 'I';
    }

    string intToRoman(int num)
    {
        int arr[] = {1000, 500, 100, 50, 10, 5, 1};
        string res = "";
        for (int i = 0; i < 7; i++)
        {
            if (num == 0)
            {
                break;
            }
            int r = num / arr[i];
            if (r == 0)
                continue;
            if (r < 4)
            {
                if (i == 6)
                {
                    for (int j = 0; j < r; j++)
                    {
                        res += getRoman(arr[i]);
                    }
                    num = num - arr[i] * r;
                    continue;
                }
                int m = (num % arr[i]) / arr[i + 1];
                if (m >= 4)
                {
                    res += getRoman(arr[i + 1]);
                    res += getRoman(arr[i - 1]);
                    num = num - arr[i - 1] + arr[i + 1];
                }
                else
                {
                    for (int j = 0; j < r; j++)
                    {
                        res += getRoman(arr[i]);
                    }
                    num = num - arr[i] * r;
                }
            }
            else
            {
                res += getRoman(arr[i]);
                res += getRoman(arr[i - 1]);
                num = num - arr[i] * r;
            }
        }
        return res;
    }
};