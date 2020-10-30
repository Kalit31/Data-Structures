#include <bits/stdc++.h>
using namespace std;

//Type: Arrays
//Approach: The idea is to first sort the pairs by height in increasing order.
//          Now, start picking up the elements from the array from left.
//          This will ensure the next element we pick up, will have height greater than the current.
//          Also, for the current element we know how many elements are ahead of it.
//          So, we can start for the 0th index and keep moving right until we find an appropriate pos to place it.
//Complexity: O(N^2) time

class Solution
{
public:
    static bool sortByHeights(const vector<int> &v1, const vector<int> &v2)
    {
        return v1[0] < v2[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        int n = people.size();
        sort(people.begin(), people.end(), sortByHeights);
        vector<vector<int>> result(n, vector<int>(2, -1));

        for (int i = 0; i < n; i++)
        {
            int currCount = people[i][1];
            for (int j = 0; j < n; j++)
            {
                if (result[j][0] == -1 && currCount == 0)
                {
                    result[j] = {people[i][0], people[i][1]};
                    break;
                }
                if (result[j][0] == -1 || result[j][0] >= people[i][0])
                {
                    currCount--;
                }
            }
        }
        return result;
    }
};