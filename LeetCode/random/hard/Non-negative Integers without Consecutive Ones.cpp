#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string N;
    int ans = 0;

    bool check(int n)
    {
        int i = 31;
        while (i > 0)
        {
            if ((n & (1 << i)) != 0 && (n & (1 << (i - 1))) != 0)
                return false;
            i--;
        }
        return true;
    }

    int find(int i, int sum, int num, bool prev)
    {
        if (sum > num)
            return 0;
        if (1 << i > num)
            return 1;
        if (prev)
            return find(i + 1, sum, num, false);
        return find(i + 1, sum, num, false) + find(i + 1, sum + (1 << i), num, true);
    }

    void build(string &s)
    {
        if (s.size() > N.size())
        {
            return;
        }
        if (s.size() == N.size() && N.compare(s) < 0)
        {
            return;
        }
        else if (N.compare(s) == 0)
        {
            ans++;
            return;
        }

        if (s[0] == '1')
        {
            ans++;
        }
        if (s[0] == '0')
        {
            int len = s.size();
            s = "0" + s;
            build(s);
            while (s.size() != len)
            {
                s.erase(s.begin());
            }
            s = "1" + s;
            s[0] = '1';
            build(s);
        }
        else
        {
            s = "0" + s;
            build(s);
        }
    }

    int findIntegers(int num)
    {
        // Approach 1
        // N = "";
        // while(num){
        //     N += num%2?"1":"0";
        //     num/=2;
        // }
        // reverse(N.begin(),N.end());
        // ans = 1;
        // string s1 = "0";
        // build(s1);
        // string s2 = "1";
        // build(s2);
        // return ans;

        // Approach 2
        // int count = 0;
        // for (int i = 0; i <= num; i++)
        //     if (check(i))
        //         count++;
        // return count;

        // Approach 3
        return find(0, 0, num, false);
    }
};