#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        vector<int> result(num_people, 0);
        int curr = 1;
        int i = 0;
        while (candies > 0)
        {
            if (curr <= candies)
            {
                result[i % num_people] = result[i % num_people] + curr;
                candies = candies - curr;
                curr++;
            }
            else
            {
                result[i % num_people] = result[i % num_people] + candies;
                candies = 0;
            }
            i++;
        }
        return result;
    }
};