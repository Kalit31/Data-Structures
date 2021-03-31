#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Compare
    {
        bool operator()(pair<double, pair<int, int>> const &p1, pair<double, pair<int, int>> const &p2)
        {
            double a1 = p1.first;
            double a11 = (1.0 * (p1.second.first + 1)) / (p1.second.second + 1);
            double a2 = p2.first;
            double a22 = (1.0 * (p2.second.first + 1)) / (p2.second.second + 1);
            return (a11 - a1) < (a22 - a2);
        }
    };

    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        int numClass = classes.size();
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, Compare> q;

        for (int i = 0; i < numClass; i++)
        {
            double avg = (1.0 * classes[i][0]) / classes[i][1];
            q.push({avg, {classes[i][0], classes[i][1]}});
        }
        while (extraStudents)
        {
            auto it = q.top();
            q.pop();
            it.second.second += 1;
            it.second.first += 1;
            double avg = (1.0 * it.second.first) / it.second.second;
            q.push({avg, {it.second.first, it.second.second}});
            extraStudents--;
        }
        double sum = 0;
        while (!q.empty())
        {
            auto it = q.top();
            q.pop();
            sum += it.first;
        }
        sum /= numClass;
        return sum;
    }
};