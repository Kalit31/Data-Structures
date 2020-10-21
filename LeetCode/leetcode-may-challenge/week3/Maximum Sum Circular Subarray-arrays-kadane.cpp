#include <bits/stdc++.h>
using namespace std;

//Type: Arrays, Kadane's Algorithm
//Approach: There are two cases possible.
//          1. There is no wrapping of array. The solution for this could be found out by Kadane's algo
//          2. There is wrapping of array. Wrapping of array simply means a block of array
//             is not included in finding the sum. This block can be though simply as the minimum possible sum.
//          The final answer would be the maximum of the 2 cases.
//Complexity: O(N) time

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &A)
    {

        int maxNoWrap = kadane(A);

        int sumArray = 0;
        bool allNegative = true;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] > 0)
            {
                allNegative = false;
            }
            sumArray += A[i];
            A[i] = -A[i];
        }

        if (allNegative)
            return maxNoWrap;

        int minSubArray = kadane(A);

        int maxWrap = sumArray + minSubArray;

        return (max(maxNoWrap, maxWrap));
    }

    int kadane(vector<int> &A)
    {
        int max_sum = A[0];
        int curr_sum = A[0];
        for (int i = 1; i < A.size(); i++)
        {
            curr_sum = max(curr_sum + A[i], A[i]);
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
};

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &A)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = A.size();
        int max_straight_SUM = INT_MIN;
        int min_straight_SUM = INT_MAX;
        int array_SUM = 0;

        int temp_maxSUM = 0;
        int temp_minSUM = 0;

        for (int i = 0; i < n; ++i)
        {
            array_SUM += A[i];

            temp_maxSUM += A[i];
            max_straight_SUM = max_straight_SUM < temp_maxSUM ? temp_maxSUM : max_straight_SUM;
            temp_maxSUM = temp_maxSUM < 0 ? 0 : temp_maxSUM;

            temp_minSUM += A[i];
            min_straight_SUM = min_straight_SUM > temp_minSUM ? temp_minSUM : min_straight_SUM;
            temp_minSUM = temp_minSUM > 0 ? 0 : temp_minSUM;
        }
        if (array_SUM == min_straight_SUM)
            return max_straight_SUM;
        return max(max_straight_SUM, (array_SUM - min_straight_SUM));
    }
};
