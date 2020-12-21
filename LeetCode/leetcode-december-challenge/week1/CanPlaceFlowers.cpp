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
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int count = 0;
        int sz = flowerbed.size();
        for (int i = 0; i < sz; i++)
        {
            if (flowerbed[i] == 1)
            {
                i++;
            }
            else
            {
                if (i + 1 < sz && flowerbed[i + 1] != 1)
                {
                    count++;
                    i++;
                }
                else if (i + 1 == sz)
                {
                    count++;
                }
            }
        }
        if (count >= n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};