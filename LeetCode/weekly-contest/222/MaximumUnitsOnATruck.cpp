#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool comp1(const vector<int> &b1, const vector<int> &b2)
    {
        return b1[1] > b2[1];
    }

    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), comp1);
        int maxUnits = 0;
        int currBoxes = 0;
        int i = 0;
        int n = boxTypes.size();
        while (i < n && currBoxes < truckSize)
        {
            vector<int> b = boxTypes[i];
            int nBox = b[0];
            int eachBox = b[1];
            if (currBoxes + nBox <= truckSize)
            {
                maxUnits += nBox * eachBox;
                currBoxes += nBox;
            }
            else
            {
                int m = truckSize - currBoxes;
                maxUnits += m * eachBox;
                currBoxes = truckSize;
            }
            i++;
        }
        return maxUnits;
    }
};