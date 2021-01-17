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
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces)
    {
        int n = arr.size();
        int m = pieces.size();
        int ptr = 0;
        while (ptr < n)
        {
            int toFind = arr[ptr];
            bool found = false;
            for (int i = 0; i < m; i++)
            {
                if (pieces[i][0] == toFind)
                {
                    found = true;
                    for (int j = 0; j < pieces[i].size(); j++)
                    {
                        if (ptr == n && j != pieces[i].size())
                        {
                            return false;
                        }
                        if (arr[ptr] != pieces[i][j])
                        {
                            return false;
                        }
                        ptr++;
                    }
                }
            }
            if (!found)
            {
                return false;
            }
        }
        return true;
    }
};