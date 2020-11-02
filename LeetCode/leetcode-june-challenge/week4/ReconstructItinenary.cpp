#include <bits/stdc++.h>
using namespace std;

//Type: Maps + Stacks + Logic
//Approach: Form an adjacency list for the cities.
//          The adjacency list is implemented through maps, and values are multisets to keep cities sorted.
//          Push "JFK" in the stack initially. Start iterating by popping top of stack,
//          and pushing the appropriate next city into it.
//          If we reach a dead end, pop the current city and push it into answer,
//          else push the next city into stack and continue.
//          The final answer would be the reverse of the current result.

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