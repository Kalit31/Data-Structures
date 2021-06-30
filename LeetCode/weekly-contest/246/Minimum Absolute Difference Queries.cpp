#include <bits/stdc++.h>
using namespace std;

//Using prefix sums
class Solution
{
public:
    vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<vector<int>> freq(n + 1, vector<int>(101, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= 100; j++)
            {
                freq[i + 1][j] = freq[i][j];
            }
            freq[i + 1][nums[i]]++;
        }

        int q = queries.size();
        vector<int> ans(q);

        for (int i = 0; i < q; i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];

            int last = -1;
            int currAns = INT_MAX;
            for (int j = 1; j <= 100; j++)
            {
                if ((freq[r + 1][j] - freq[l][j]) != 0)
                {
                    if (last == -1)
                    {
                        last = j;
                    }
                    else
                    {
                        currAns = min(currAns, j - last);
                        last = j;
                    }
                }
            }
            ans[i] = currAns == INT_MAX ? -1 : currAns;
        }
        return ans;
    }
};

//Miscalculated the constraints, applied Mo's algorithm
class Solution
{
public:
    struct Query
    {
        int ind, l, r;
        bool operator<(Query other) const
        {
            return make_pair(l / 318, r) < make_pair(other.l / 318, other.r);
        }
    };

    void add(int x, multiset<int> &s, map<int, int> &mp)
    {
        s.insert(x);
        int left = *(--s.find(x));
        int right = *(++s.find(x));
        mp[abs(left - x)]++;
        mp[abs(right - x)]++;
        mp[abs(left - right)]--;
        if (mp[abs(left - right)] == 0)
            mp.erase(abs(left - right));
    }

    void remove(int x, multiset<int> &s, map<int, int> &mp)
    {
        int left = *(--s.find(x));
        int right = *(++s.find(x));
        s.erase(s.find(x));

        mp[abs(left - x)]--;
        if (mp[abs(left - x)] == 0)
            mp.erase(abs(left - x));
        mp[abs(right - x)]--;
        if (mp[abs(right - x)] == 0)
            mp.erase(abs(right - x));

        mp[abs(left - right)]++;
    }

    vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int q = queries.size();
        cout << "N:" << n << endl;
        vector<int> ans(q);

        //block_size = max(1, int(pow(n, 1.0 / 2.0)));

        vector<Query> Queries(q);
        for (int i = 0; i < q; i++)
        {
            Queries[i].ind = i;
            Queries[i].l = queries[i][0];
            Queries[i].r = queries[i][1];
        }
        sort(Queries.begin(), Queries.end());

        multiset<int> s;
        map<int, int> mp;
        const int MOD = 100000;

        s.insert(-MOD);
        s.insert(MOD);

        mp[2 * MOD] = 1;

        int r = -1;
        int l = 0;
        for (int i = 0; i < q; i++)
        {
            // cout << "(" << Queries[i].l << "," << Queries[i].r << ")" << endl;
            while (r < Queries[i].r)
            {
                r++;
                // cout<<"ADDING:"<<nums[r]<<endl;
                add(nums[r], s, mp);
            }
            while (l > Queries[i].l)
            {
                l--;
                //cout<<"ADDING:"<<nums[l]<<endl;
                add(nums[l], s, mp);
            }
            while (r > Queries[i].r)
            {
                // cout<<"REMOVING:"<<nums[r]<<endl;
                remove(nums[r], s, mp);
                r--;
            }
            while (l < Queries[i].l)
            {
                //cout<<"REMOVING:"<<nums[l]<<endl;
                remove(nums[l], s, mp);
                l++;
            }
            bool found = false;
            auto it = mp.begin();
            if (it->first == 0)
            {
                it++;
            }
            if (it == mp.end() || it->first > 100)
                ans[Queries[i].ind] = -1;
            else
                ans[Queries[i].ind] = it->first;
        }

        return ans;
    }
};