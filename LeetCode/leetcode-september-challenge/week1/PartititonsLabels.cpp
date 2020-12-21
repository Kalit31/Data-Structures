#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string S)
    {
        vector<pair<int, int>> result;
        int n = S.size();
        for (int i = 0; i < n; i++)
        {
            char ch = S[i];
            // this step is consuming time
            // optimization -> store the last index of each character
            int ind = S.find_last_of(ch);
            if (result.empty())
            {
                result.push_back({i, ind});
            }
            else
            {
                pair<int, int> p = result.back();
                int s = p.first;
                int e = p.second;
                if (i >= s && ind <= e)
                {
                    continue;
                }
                else if (i <= e && ind > e)
                {
                    p.second = ind;
                    result.pop_back();
                    result.push_back(p);
                }
                else if (i > e)
                {
                    pair<int, int> p = {i, ind};
                    result.push_back(p);
                }
            }
        }
        vector<int> arr;
        for (int i = 0; i < result.size(); i++)
        {
            arr.push_back(result[i].second - result[i].first + 1);
        }
        return arr;
    }
};

class Solution
{
public:
    vector<int> partitionLabels(string S)
    {
        vector<int> lastIndex(26, -1);
        int startIndex, endIndex;
        vector<int> vec;
        int i, size;
        size = S.size();
        for (i = 0; i < size; i++)
            lastIndex[S[i] - 'a'] = i;

        for (i = 0; i < size; i++)
        {
            startIndex = i;
            endIndex = lastIndex[S[i] - 'a'];

            while (i + 1 < size && i + 1 <= endIndex)
            {
                i++;
                if (lastIndex[S[i] - 'a'] > endIndex)
                    endIndex = lastIndex[S[i] - 'a'];
            }
            vec.push_back(endIndex - startIndex + 1);
        }
        return vec;
    }
};