#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        vector<int> timeFreq(60, 0);
        int n = time.size();

        for (int i = 0; i < n; i++)
        {
            time[i] = time[i] % 60;
        }

        timeFreq[time[0]] = 1;

        int count = 0;

        for (int i = 1; i < n; i++)
        {
            if (time[i] == 0)
            {
                count += timeFreq[0];
            }
            else if (timeFreq[60 - time[i]] != 0)
            {
                count += timeFreq[60 - time[i]];
            }
            timeFreq[time[i]]++;
        }

        return count;
    }
};