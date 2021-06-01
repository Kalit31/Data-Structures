#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        vector<vector<string>> result;
        for (int i = 1; i <= searchWord.size(); i++)
        {
            string word = searchWord.substr(0, i);
            vector<string> currResult;
            for (int j = 0; j < products.size(); j++)
            {
                string currProd = products[j];
                bool poss = true;
                if (currProd.size() < word.size())
                {
                    poss = false;
                }
                else
                {
                    for (int k = 0; k < word.size(); k++)
                    {
                        if (currProd[k] != word[k])
                        {
                            poss = false;
                            break;
                        }
                    }
                }
                if (poss)
                {
                    currResult.push_back(currProd);
                }
            }
            sort(currResult.begin(), currResult.end());
            vector<string> resultToPush;
            for (int j = 0; j < min(3, (int)currResult.size()); j++)
            {
                resultToPush.push_back(currResult[j]);
            }
            result.push_back(resultToPush);
        }
        return result;
    }
};