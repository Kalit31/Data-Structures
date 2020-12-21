#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calc(vector<int> &dp, vector<int> &prices, int currDay, int days)
    {
        if (currDay >= days)
        {
            return 0;
        }
        if (dp[currDay] != -1)
        {
            return dp[currDay];
        }
        int ans = 0;
        for (int i = currDay + 1; i < days; i++)
        {
            if (prices[i] > prices[currDay])
            {
                ans = max(ans, prices[i] - prices[currDay] + calc(dp, prices, i + 2, days));
            }
        }
        ans = max(ans, calc(dp, prices, currDay + 1, days));
        dp[currDay] = ans;
        return ans;
    }

    int maxProfit(vector<int> &prices)
    {
        int days = prices.size();
        if (days == 0 || days == 1)
        {
            return 0;
        }
        vector<int> dp(days + 1, -1);
        calc(dp, prices, 0, days);
        return dp[0];
    }
};

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1)
            return 0;
        vector<int> noStock(n, 0), inHand(n, 0), Sold(n, 0);

        noStock[0] = 0;
        inHand[0] = -prices[0];
        Sold[0] = 0;

        for (int i = 1; i < n; ++i)
        {
            noStock[i] = max(noStock[i - 1], Sold[i - 1]);
            inHand[i] = max(inHand[i - 1], noStock[i - 1] - prices[i]);
            Sold[i] = inHand[i - 1] + prices[i];
        }
        int result = max(noStock[n - 1], Sold[n - 1]);
        return result;
    }
};

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1)
        {
            return 0;
        }
        else if (n == 2)
        {
            if (prices[1] > prices[0])
            {
                return (prices[1] - prices[0]);
            }
            else
            {
                return 0;
            }
        }

        int dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);
        dp[1][1] = max(dp[0][1], dp[0][0] - prices[1]);

        for (int i = 2; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][1] + prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 2][0] - prices[i], dp[i - 1][1]);
        }

        return dp[n - 1][0];
    }
};