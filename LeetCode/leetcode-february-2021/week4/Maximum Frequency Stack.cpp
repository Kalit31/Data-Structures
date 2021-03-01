#include <bits/stdc++.h>
using namespace std;

class FreqStack
{
public:
    map<int, int> m1;
    map<int, stack<int>> m2;
    int currMax;

    FreqStack()
    {
        currMax = 0;
    }

    void push(int x)
    {
        m1[x]++;
        if (m1[x] > currMax)
        {
            currMax = m1[x];
        }
        m2[m1[x]].push(x);
    }

    int pop()
    {
        if (m2[currMax].empty())
            return -1;
        int ans = m2[currMax].top();
        m2[currMax].pop();
        m1[ans]--;
        if (m2[currMax].empty())
        {
            currMax--;
        }
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */