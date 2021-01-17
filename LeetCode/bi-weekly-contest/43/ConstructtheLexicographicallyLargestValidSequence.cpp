#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool build(vector<int> &result, vector<bool> &visited, int curr)
    {
        if (curr == result.size())
        {
            return true;
        }
        if (result[curr] != 0)
        {
            return build(result, visited, curr + 1);
        }
        int n = visited.size();
        n--;
        for (int j = n; j >= 1; j--)
        {
            if (visited[j])
            {
                continue;
            }
            if (j == 1)
            {
                visited[j] = true;
                result[curr] = j;
                if (build(result, visited, curr + 1))
                {
                    return true;
                }
                visited[j] = false;
                result[curr] = 0;
            }
            else
            {
                if (curr + j < result.size() && result[curr + j] == 0)
                {
                    visited[j] = true;
                    result[curr] = j;
                    result[curr + j] = j;
                    if (build(result, visited, curr + 1))
                    {
                        return true;
                    }
                    visited[j] = false;
                    result[curr] = 0;
                    result[curr + j] = 0;
                }
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n)
    {
        vector<int> result(2 * n - 1, 0);
        vector<bool> visited(n + 1, false);
        build(result, visited, 0);
        return result;
    }
};