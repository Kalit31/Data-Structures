#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, multiset<string>> adjList;
        vector<string> result;
        int n = tickets.size();
        for (int i = 0; i < n; i++)
        {
            adjList[tickets[i][0]].insert(tickets[i][1]);
        }
        stack<string> st;
        st.push("JFK");
        while (!st.empty())
        {
            string curr = st.top();
            if (adjList[curr].size() == 0)
            {
                st.pop();
                result.push_back(curr);
            }
            else
            {
                st.push(*(adjList[curr].begin()));
                adjList[curr].erase(adjList[curr].begin());
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};