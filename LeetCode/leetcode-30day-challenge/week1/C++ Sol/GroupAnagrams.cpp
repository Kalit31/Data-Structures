#include <bits/stdc++.h>
using namespace std;

//Type: Strings, Maps

//Approach: We maintain the result and a map to store the index of the first unique anagram.
//          A pointer j tells us about the number of unique anagram strings encountered.
//          Start traversing the array, sort it. If this is not found in the map,
//          add a new entry in the map, with the index of the first anagram.
//          If the sorted string was found, simply push in the result.
//          The correct index for the result array is found out using the map.
//Complexity: O(N) time and O(N) space

class OptimizeSolution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<string>> result;
        unordered_map<string, int> stringMap;

        for (int i(0), j(0); i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if (!stringMap.count(temp))
            {
                stringMap[temp] = j++;
                result.push_back({});
            }
            result[stringMap[temp]].push_back(strs[i]);
        }
        return result;
    }
};

class MySolution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<string>> result;
        unordered_map<string, vector<string>> stringMap;

        for (string s : strs)
        {
            string temp = s;
            sort(s.begin(), s.end());
            if (stringMap.count(s))
            {
                vector<string> v = stringMap[s];
                v.push_back(temp);
                stringMap[s] = v;
            }
            else
            {
                vector<string> v;
                v.push_back(temp);
                stringMap[s] = v;
            }
        }

        for (auto it = stringMap.begin(); it != stringMap.end(); it++)
        {
            result.push_back(it->second);
        }
        return result;
    }
};