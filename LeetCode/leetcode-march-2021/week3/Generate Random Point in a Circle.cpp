#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double r = 0;
    double x = 0;
    double y = 0;
    double PI = 3.14159265358979323846;

    Solution(double radius, double x_center, double y_center)
    {
        r = radius;
        x = x_center;
        y = y_center;
    }

    double randBw0and1()
    {
        return (double)rand() / RAND_MAX;
    }

    vector<double> randPoint()
    {
        double theta = 2 * PI * randBw0and1();
        double len = r * sqrt(randBw0and1());
        double xCoord = x + len * cos(theta);
        double yCoord = y + len * sin(theta);
        return {xCoord, yCoord};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */