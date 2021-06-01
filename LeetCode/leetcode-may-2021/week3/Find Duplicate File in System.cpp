#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        vector<vector<string>> result;
        map<string, vector<string>> mp;

        for (int i = 0; i < paths.size(); i++)
        {
            string curr = paths[i];
            int n = curr.size();
            int j = 0;
            while (curr[j] != ' ')
            {
                j++;
            }
            string base = curr.substr(0, j);
            j++;
            while (j < n)
            {
                int startFileName = j;
                while (curr[j] != '(')
                {
                    j++;
                }
                string filename = curr.substr(startFileName, j - startFileName);
                //cout<<filename<<endl;
                j++;
                int startContent = j;
                while (curr[j] != ')')
                {
                    j++;
                }
                string content = curr.substr(startContent, j - startContent);
                //cout<<content<<endl;
                j++;
                j++;
                string completePath = base + "/" + filename;
                mp[content].push_back(completePath);
            }
        }

        for (auto it : mp)
        {
            if (it.second.size() > 1)
            {
                result.push_back(it.second);
            }
        }
        return result;
    }
};