#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        int n = courses.size();

        auto comp = [](const vector<int> &c1, const vector<int> &c2) -> bool {
            return c1[1] < c2[1];
        };

        sort(courses.begin(), courses.end(), comp);

        priority_queue<int> pq;

        int currTime = 0;

        for (int i = 0; i < n; i++)
        {
            if (currTime + courses[i][0] <= courses[i][1])
            {
                pq.push(courses[i][0]);
                currTime += courses[i][0];
            }
            else if (!pq.empty() && pq.top() > courses[i][0])
            {
                currTime = currTime - pq.top() + courses[i][0];
                pq.pop();
                pq.push(courses[i][0]);
            }
        }
        return pq.size();
    }
};

class Solution
{
public:
    int build(vector<vector<int>> &courses, int currDay, int currIndex, vector<vector<int>> &dp)
    {
        if (currIndex == courses.size())
        {
            return 0;
        }

        if (dp[currIndex][currDay] != -1)
        {
            return dp[currIndex][currDay];
        }

        auto curr = courses[currIndex];

        int ans = 0;

        //take course if possible
        if (currDay + curr[0] <= curr[1])
        {
            ans = max(ans, 1 + build(courses, currDay + curr[0], currIndex + 1, dp));
        }

        //do not take course
        ans = max(ans, build(courses, currDay, currIndex + 1, dp));

        return dp[currIndex][currDay] = ans;
    }

    int scheduleCourse(vector<vector<int>> &courses)
    {
        int n = courses.size();

        auto comp = [](const vector<int> &c1, const vector<int> &c2) -> bool {
            return c1[1] < c2[1];
        };

        sort(courses.begin(), courses.end(), comp);

        // for(int i=0;i<courses.size();i++){
        //     cout<<courses[i][0]<<" - "<<courses[i][1]<<endl;
        // }

        vector<vector<int>> dp(n, vector<int>(courses[n - 1][1] + 1, -1));

        return build(courses, 0, 0, dp);
    }
};