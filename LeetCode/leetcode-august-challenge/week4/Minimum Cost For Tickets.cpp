#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int dp[366];
    vector<int> duration = {1,7,30};
    
    int build(vector<int>& days, vector<int>& costs, int currDay){
        int n = days.size();
        if(currDay == days.size()){
            return 0;
        }
        if(dp[currDay]!=-1){
            return dp[currDay];
        }
        int ans = INT_MAX;
        for(int type=0;type<3;type++){
            //buy ticket of type(0,1,2), and find the next appropriate day to buy another ticket
            int day = currDay;
            while(day<n && days[day] < days[currDay] + duration[type]){
                day++;
            }
            ans = min(ans,build(days,costs,day)+costs[type]);
        }
        return dp[currDay]=ans;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        int totalCost = build(days,costs,0);
        return totalCost;
    }
};
