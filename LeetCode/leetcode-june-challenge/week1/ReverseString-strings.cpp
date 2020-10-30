#include <bits/stdc++.h>
using namespace std;

//Type: Strings, Arrays
//Approach: Apply simple reversing algorithm
//Complexity: O(N) time and O(1) space

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            swap(s[i], s[n - i - 1]);
        }
    }
};

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            char tmp = s[left];
            s[left++] = s[right];
            s[right--] = tmp;
        }
    }
};