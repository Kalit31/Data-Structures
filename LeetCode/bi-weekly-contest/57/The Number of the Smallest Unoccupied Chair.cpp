#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        int n = times.size();
        vector<int> result(n);

        set<array<int, 3>> st;

        for (int i = 0; i < n; i++)
        {
            st.insert({times[i][0], times[i][1], i});
        }

        int chair = 0;
        while (!st.empty())
        {
            auto start = st.begin();
            array<int, 3> curr = *start;
            result[curr[2]] = chair;
            int nxt = curr[1];
            st.erase(start);

            while (true)
            {
                auto it = st.lower_bound({nxt, nxt, 0});
                if (it == st.end())
                {
                    break;
                }
                array<int, 3> curr = *it;
                result[curr[2]] = chair;
                nxt = curr[1];
                st.erase(it);
            }
            chair++;
        }
        return result[targetFriend];
    }
};