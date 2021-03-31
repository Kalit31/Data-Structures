#include <bits/stdc++.h>
using namespace std;

//Type: Arrays, Greedy algorithms

//Approach: As we can engage in as many transactions as required, we shall follow the
//          the greedy approach. It simply means, capture any sort of profit possible
//          between two consecutive days.
//          We would start traversing the array and check whether the previous day had
//          a lower price. If yes, greedily add the profit and continue.
//Complexity: O(N) time and O(1) space

class MySolution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        for(int i=0;i<prices.size()-1;i++){
            profit += max(0,prices[i+1]-prices[i]);
        }
        return profit;
    }
};

class OptimizeSolution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        int minval = prices[0];
        int maxval = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] < prices[i - 1])
            {
                if (maxval > minval)
                {
                    profit += (maxval - minval);
                }
                minval = prices[i];
                maxval = prices[i];
                continue;
            }
            maxval = prices[i];
        }
        profit += (maxval - minval);
        return profit;
    }
};
