#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfRounds(string startTime, string finishTime)
    {
        int startHr = stoi(startTime.substr(0, 2));
        int startMin = stoi(startTime.substr(3, 2));
        int fHr = stoi(finishTime.substr(0, 2));
        int fMin = stoi(finishTime.substr(3, 2));

        int ans = 0;

        while (startHr != fHr || startMin != fMin)
        {
            if (startMin % 15 == 0)
            {
                ans++;
            }
            startMin++;
            if (startMin == 60)
            {
                startMin = 0;
                startHr++;
                if (startHr == 24)
                {
                    startHr = 0;
                }
            }
        }
        ans = max(0, startMin % 15 == 0 ? ans : ans - 1);
        return ans;
    }
};