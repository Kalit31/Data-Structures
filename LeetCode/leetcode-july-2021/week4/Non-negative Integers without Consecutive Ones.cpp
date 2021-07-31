#include <bits/stdc++.h>
using namespace std;

//Type: Digit DP
class Solution
{
public:
    string binaryRep(int n)
    {
        string result = "";

        while (n)
        {
            if (n & 1)
            {
                result += "1";
            }
            else
            {
                result += "0";
            }
            n /= 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    int dp[31][2][2];
    int build(string &num, int idx, bool tight, bool wasLastOne)
    {
        int n = num.size();
        if (idx == n)
        {
            return 1;
        }
        if (dp[idx][tight][wasLastOne] != -1)
        {
            return dp[idx][tight][wasLastOne];
        }
        char currCh = num[idx];
        int ans = 0;
        if (tight)
        {
            if (currCh == '1')
            {
                //if we place a '0', we remove the tight constraint
                //place a '0'
                ans += build(num, idx + 1, false, false);
                if (!wasLastOne)
                {
                    //if last was not one, we can place a '1' here keeping the tight constraint
                    ans += build(num, idx + 1, true, true);
                }
            }
            else
            {
                //can only place a '0' here keeping the tight constraint
                ans += build(num, idx + 1, true, false);
            }
        }
        else
        {
            //can place either '0' or '1'
            if (wasLastOne)
            {
                //can only place a '0'
                ans += build(num, idx + 1, false, false);
            }
            else
            {
                //place a '0'
                ans += build(num, idx + 1, false, false);
                //place a '1'
                ans += build(num, idx + 1, false, true);
            }
        }
        return dp[idx][tight][wasLastOne] = ans;
    }

    int findIntegers(int n)
    {
        string num = binaryRep(n);
        memset(dp, -1, sizeof(dp));
        return build(num, 0, true, false);
    }
};