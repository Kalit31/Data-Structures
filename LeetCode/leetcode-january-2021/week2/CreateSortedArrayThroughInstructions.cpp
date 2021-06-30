#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    struct FenwickTree
    {
        vector<int> bit; // binary indexed tree
        int n;

        FenwickTree(int n)
        {
            this->n = n;
            bit.assign(n, 0);
        }

        FenwickTree(vector<int> a) : FenwickTree(a.size())
        {
            for (size_t i = 0; i < a.size(); i++)
                add(i, a[i]);
        }

        int sum(int r)
        {
            int ret = 0;
            for (; r >= 0; r = (r & (r + 1)) - 1)
                ret += bit[r];
            return ret;
        }

        int sum(int l, int r)
        {
            return sum(r) - sum(l - 1);
        }

        void add(int idx, int delta)
        {
            for (; idx < n; idx = idx | (idx + 1))
                bit[idx] += delta;
        }
    };

    int createSortedArray(vector<int> &instructions)
    {
        const int N = 1e5 + 5;
        FenwickTree tree(N);
        const int mod = 1e9 + 7;
        int n = instructions.size();
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ll cntLess = tree.sum(instructions[i] - 1);
            //cntMore = #(elements addTillNow) - (elements<=instructions[i])
            ll cntMore = (i - tree.sum(instructions[i]));
            ans = (ans + min(cntLess, cntMore)) % mod;
            tree.add(instructions[i], 1);
        }
        return ans;
    }
};