#include <bits/stdc++.h>
using namespace std;

//Type: Stacks
//Approach:
//Complexity: O(N) time

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    int i;

    StockSpanner()
    {
        i = -1;
    }

    int next(int price)
    {
        i++;
        while (!st.empty() && st.top().second <= price)
        {
            st.pop();
        }
        if (st.empty())
        {
            st.push({i, price});
            return i + 1;
        }

        int index = st.top().first;
        st.push({i, price});
        return i - index;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */