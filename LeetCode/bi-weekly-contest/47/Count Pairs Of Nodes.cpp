#include <bits/stdc++.h>
using namespace std;

/*
The intuitive solution is easy to come up with. 
For each node pair (a, b), the number of edges incident to a or b can be 
calculated as cnt = degree(a) + degree(b) - num_edges(a, b). 
The diffcult part is how to calculate the number of pairs with cnt > query.

Here can use a two-step strategy, first find all potential pairs with degree(a) + degree(b) > query, 
then remove those pairs with degree(a) + degree(b) - num_edges(a, b) < query. 
The first step can be solved by using two pointers with a sorted array (time complexity, O(nlgn). 
Here can also use the counting sort to optimze to O(n)). 
The second step just needs to traverse all edges (time complexity, O(E)).
*/

class Solution
{
public:
    vector<int> countPairs(int n, vector<vector<int>> &edges, vector<int> &queries)
    {
        int num = edges.size();

        vector<int> cnt(n, 0);
        map<array<int, 2>, int> mp;

        for (int i = 0; i < num; i++)
        {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            cnt[u]++;
            cnt[v]++;
            if (u > v)
            {
                swap(u, v);
            }
            mp[{u, v}]++;
        }

        vector<int> freq = cnt;
        sort(freq.begin(), freq.end());

        vector<int> ans;

        for (int q : queries)
        {
            int c = 0;

            for (int i = 0, j = n - 1; i < n; i++)
            {
                while (j >= 0 and freq[i] + freq[j] > q)
                    j--;
                c += n - j - 1;
                if (cnt[i] * 2 > q)
                    c -= 1;
            }
            c /= 2;
            for (auto it = mp.begin(); it != mp.end(); it++)
            {
                if (cnt[(it->first)[0]] + cnt[(it->first)[1]] > q && cnt[(it->first)[0]] + cnt[(it->first)[1]] - (it->second) <= q)
                {
                    c--;
                }
            }
            ans.push_back(c);
        }
        return ans;
    }
};

// TLE Solution
class Solution
{
public:
    vector<int> countPairs(int n, vector<vector<int>> &edges, vector<int> &queries)
    {
        int num = edges.size();

        vector<vector<int>> g(n, vector<int>(n, 0));
        vector<int> cnt(n, 0);

        for (int i = 0; i < num; i++)
        {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            g[u][v]++;
            g[v][u]++;
            cnt[u]++;
            cnt[v]++;
        }

        vector<int> arr;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int curr = cnt[i] + cnt[j] - g[i][j];
                arr.push_back(curr);
            }
        }

        sort(arr.begin(), arr.end());

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            auto it = upper_bound(arr.begin(), arr.end(), queries[i]);
            int diff = distance(arr.begin(), it);
            ans.push_back(arr.size() - diff);
        }

        return ans;
    }
};