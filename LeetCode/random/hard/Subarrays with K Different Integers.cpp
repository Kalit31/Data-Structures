#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int atmostK(vector<int> &arr, int k)
    {
        int n = arr.size();
        int cnt = 0;
        int ptr1 = 0;
        int ptr2 = 0;
        map<int, int> mp;

        while (ptr2 < n)
        {
            mp[arr[ptr2]]++;

            while (mp.size() > k)
            {
                mp[arr[ptr1]]--;
                if (mp[arr[ptr1]] == 0)
                {
                    mp.erase(arr[ptr1]);
                }
                ptr1++;
            }
            cnt += ptr2 - ptr1 + 1;
            ptr2++;
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int> &A, int K)
    {
        int ans = atmostK(A, K) - atmostK(A, K - 1);
        return ans;
    }
};