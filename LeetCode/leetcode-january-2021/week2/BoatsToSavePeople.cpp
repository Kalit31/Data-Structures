#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int n = people.size();
        int ans = 0;
        int ptr1 = 0;
        int ptr2 = n - 1;
        sort(people.begin(), people.end());
        while (ptr1 <= ptr2)
        {
            ans++;
            if (people[ptr1] + people[ptr2] <= limit)
            {
                //can combine heavy and light
                ptr1++;
                ptr2--;
            }
            else
            {
                //give a single boat to the heavy
                ptr2--;
            }
        }
        return ans;
    }
};