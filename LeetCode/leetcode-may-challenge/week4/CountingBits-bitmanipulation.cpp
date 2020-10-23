#include <bits/stdc++.h>
using namespace std;

//Type: Bit Manipultation, Math
//Approach: 0: 00
//          1: 01
//          2: 10
//          3: 11
//          The fact to observe here is that if the number is even,
//          the number of bits is simply equal to number of bits in (num)/2
//          else if the number is odd, the no. of bits is equal to num of bits in (num)/2 + 1
//          We can start with intitalizing the base, and find the solution iteratively.
//Complexity: O(N) time

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> result(num + 1);
        result[0] = 0;
        for (int i = 1; i <= num; i++)
        {
            result[i] = result[i / 2] + i % 2;
        }
        return result;
    }
};