#include <bits/stdc++.h>
using namespace std;

//Type: Dynamic Programming
//Approach: We fill the dp table top to bottom
//          The elements in the first row (word1 is empty), are simply the number of characters till that col (All insertions)
//          The elements in the first col (word2 is empty), are simply the number of characters till that row (All deletions)
//          At any other cell in  the table,
//          If the character of word1 and word2 match, we do not have to perform any operation, and copy the result of the above-left cell.
//          Else if characters do not match, we may have to find which of the following among the three operations
//          would yield the minimum.
//Complexity: O(L1*L2) time and O(L1*L2) space

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int l1 = word1.length();
        int l2 = word2.length();
        int dp[l1 + 1][l2 + 1];

        for (int i = 0; i <= l1; i++)
        {
            for (int j = 0; j <= l2; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = j;
                }
                else if (j == 0)
                {
                    dp[i][j] = i;
                }
                else if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                }
            }
        }
        return dp[l1][l2];
    }
};