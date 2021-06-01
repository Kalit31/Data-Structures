#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    bool isPossible(vector<int> &target)
    {
        int n = target.size();
        priority_queue<ll> q;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            q.push(target[i]);
            sum += (ll)target[i];
        }
        while (true)
        {
            if (sum == n)
            {
                return true;
            }
            ll curr = q.top();
            q.pop();
            ll remSum = sum - curr;
            if (remSum == 1)
            {
                return true;
            }
            if (remSum == 0 || curr < remSum || curr % remSum == 0)
            {
                return false;
            }
            ll newElement = curr % remSum;
            sum = newElement + remSum;
            q.push(newElement);
        }
        return true;
    }
};