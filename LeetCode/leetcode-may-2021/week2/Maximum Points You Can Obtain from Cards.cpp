#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        vector<int> pref(n, 0);
        pref[0] = cardPoints[0];
        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + cardPoints[i];
        }
        int score = 0;
        for (int i = 0; i <= k; i++)
        {
            int currScore = (i > 0 ? pref[i - 1] : 0) + (i < k ? pref[n - 1] - ((n - 1 - k + i) >= 0 ? pref[n - 1 - k + i] : 0) : 0);
            score = max(score, currScore);
        }
        return score;
    }
};