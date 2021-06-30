#include <bits/stdc++.h>
using namespace std;

class MyCalendar
{
public:
    vector<array<int, 2>> s;
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        bool poss = true;
        end--;
        for (auto curr : s)
        {
            if (curr[0] <= start && start <= (curr[1]))
            {
                poss = false;
                break;
            }

            if (curr[0] <= end && end <= (curr[1]))
            {
                poss = false;
                break;
            }

            if (start <= curr[0] && curr[1] <= end)
            {
                poss = false;
                break;
            }
        }

        if (poss)
        {
            s.push_back({start, end});
        }
        return poss;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */