#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct SegmentTree
{
    int n;
    vector<int> lo, hi;
    vector<int> vals, delta;
    vector<int> data;

    void init(int n, vector<int> x)
    {
        this->n = n;
        lo.clear();
        lo.resize(4 * n + 1);
        hi.clear();
        hi.resize(4 * n + 1);
        vals.clear();
        vals.resize(4 * n + 1, 0);
        delta.clear();
        delta.resize(4 * n + 1, 0);
        data = x;
        initializeNodes(1, 0, n - 1);
    }

    void initializeNodes(int i, int a, int b)
    {
        lo[i] = a;
        hi[i] = b;

        if (a == b)
        {
            vals[i] = data[a];
            return;
        }
        int mid = (a + b) / 2;
        initializeNodes(2 * i, a, mid);
        initializeNodes(2 * i + 1, mid + 1, b);
        updateHelper(i);
    }

    void update(int a, int b, int val)
    {
        updateNodes(1, a, b, val);
    }

    void propagate(int i)
    {
        delta[2 * i] += delta[i];
        delta[2 * i + 1] += delta[i];
        delta[i] = 0;
    }

    void updateHelper(int i)
    {
        vals[i] = min(vals[2 * i] + delta[2 * i], vals[2 * i + 1] + delta[2 * i + 1]);
    }

    void updateNodes(int i, int a, int b, int val)
    {
        if (lo[i] > b || hi[i] < a)
        {
            return;
        }
        //complete cover
        if (lo[i] >= a && b >= hi[i])
        {
            delta[i] += val;
            return;
        }

        //partial cover
        propagate(i); //push change to children
        updateNodes(2 * i, a, b, val);
        updateNodes(2 * i + 1, a, b, val);
        updateHelper(i);
    }

    int minimum(int a, int b)
    {
        return minimum(1, a, b);
    }

    int minimum(int i, int a, int b)
    {
        if (lo[i] > b || hi[i] < a)
        {
            return INT_MAX;
        }
        if (a <= lo[i] && hi[i] <= b)
        {
            return vals[i] + delta[i];
        }

        propagate(i);

        //do not update my min, bcoz minLeft and minRight may be partial covers of the subtrees

        int minLeft = minimum(2 * i, a, b);
        int minRight = minimum(2 * i + 1, a, b);

        updateHelper(i);

        int ans = min(minLeft, minRight);
        return ans;
    }
};