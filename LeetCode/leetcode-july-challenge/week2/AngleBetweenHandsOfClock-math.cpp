#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        double minAngle = (minutes / 60.0) * 360;
        double hourAngle = (hour / 12.0) * 360 + (minutes / 60.0) * 30;
        double diff = abs(minAngle - hourAngle);
        return min(diff, 360.0 - diff);
    }
};