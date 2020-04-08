#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct pair
{
    int start, end;
    pair(int s, int e)
    {
        start = s;
        end = e;
    }
};

struct less_than_pair
{
    inline bool operator()(const pair &p1, const pair &p2)
    {
        return p1.end > p2.end;
    }
};

int main()
{

    int t;
    cin >> t;
    int start[t];
    int end[t];
    for (int i = 0; i < t; i++)
    {
        cin >> start[i];
        cin >> end[i];
    }

    sort(end, end + t);

    return 0;
}