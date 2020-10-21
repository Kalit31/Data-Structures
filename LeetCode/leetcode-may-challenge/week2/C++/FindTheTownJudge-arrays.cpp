#include <bits/stdc++.h>
using namespace std;

//Type: Arrays
//Approach: Populate two arrays:
//          one is the trusts which tells a particular person trusts how many people
//          another is the trustedBy which tells a particular person is trusted by how many people
//          Now, we can easily traverse the arrays to find the town judge
//          trusts[townjudge] = 0
//          trustedBy[townjudge] = rest of population
//Complexity: O(N) time and O(N) space

class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        int trusts[N + 1];
        int trustedBy[N + 1];

        for (int i = 0; i <= N; i++)
        {
            trusts[i] = 0;
            trustedBy[i] = 0;
        }

        for (int i = 0; i < trust.size(); i++)
        {
            int t = trust[i][0];
            int tB = trust[i][1];
            trusts[t]++;
            trustedBy[tB]++;
        }

        for (int i = 1; i <= N; i++)
        {
            if (trustedBy[i] == N - 1 && trusts[i] == 0)
            {
                return i;
            }
        }
        return -1;
    }
};