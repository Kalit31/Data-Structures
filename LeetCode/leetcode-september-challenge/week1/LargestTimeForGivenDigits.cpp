#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> permutations;

    bool minuteValid(string s)
    {
        if (s[2] >= '0' && s[2] <= '5')
        {
            if (s[3] >= '0' && s[3] <= '9')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return false;
    }

    bool hourValid(string s)
    {
        if (s[0] == '2' && (s[1] >= '0' && s[1] <= '3'))
        {
            return true;
        }
        else if (s[0] == '1' && (s[1] >= '0' && s[1] <= '9'))
        {
            return true;
        }
        else if (s[0] == '0' && (s[1] >= '0' && s[1] <= '9'))
        {
            return true;
        }
        return false;
    }

    void buildPermutations(vector<int> &arr, vector<int> visited, string curr)
    {
        if (curr.size() == 4)
        {
            permutations.push_back(curr);
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            if (!visited[i])
            {
                visited[i] = 1;
                curr += to_string(arr[i]);
                buildPermutations(arr, visited, curr);
                curr.pop_back();
                visited[i] = 0;
            }
        }
    }

    string largestTimeFromDigits(vector<int> &arr)
    {
        vector<int> visited(4, 0);
        buildPermutations(arr, visited, "");
        vector<string> validTime;
        for (string s : permutations)
        {
            if (hourValid(s) && minuteValid(s))
            {
                validTime.push_back(s);
            }
        }
        if (validTime.size() == 0)
        {
            return "";
        }
        sort(validTime.begin(), validTime.end());
        string result = validTime.back().substr(0, 2) + ":" + validTime.back().substr(2, 2);
        return result;
    }
};