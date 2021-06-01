#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(long int num)
    {
        vector<int> digits;
        while (num)
        {
            digits.push_back(num % 10);
            num /= 10;
        }
        int i = 0;
        int j = digits.size() - 1;

        while (i < j)
        {
            if (digits[i] != digits[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int superpalindromesInRange(string left, string right)
    {
        int cnt = 0;

        long int l = stol(left);
        long int r = stol(right);

        for (int i = 1; i < 100000; i++)
        {
            string curr = to_string(i);
            int n = curr.size();
            for (int j = n - 1; j >= 0; j--)
            {
                curr += curr[j];
            }
            long int newNum = stol(curr);
            newNum *= newNum;
            if (newNum > r)
            {
                break;
            }

            if (newNum >= l && isPalindrome(newNum))
            {
                //  cout<<"num: "<<newNum<<endl;
                cnt++;
            }
        }

        for (int i = 1; i < 100000; i++)
        {
            string curr = to_string(i);
            int n = curr.size();
            for (int j = n - 2; j >= 0; j--)
            {
                curr += curr[j];
            }
            long int newNum = stol(curr);
            newNum *= newNum;
            if (newNum > r)
            {
                break;
            }
            if (newNum >= l && isPalindrome(newNum))
            {
                //    cout<<"num: "<<newNum<<endl;
                cnt++;
            }
        }

        return cnt;
    }
};