#include <bits/stdc++.h>
using namespace std;

//Type: Cycle Detection, Implementation

//Approach : Use the hare-tortoise analogy to check the presence of a cycle.
//           If a cycle is present, we simply return false, since we cannot reach 1.
//           But if a cycle is not detected, we check the final value is equal to 1.
//           If yes, return true else false.

int next_n(int n)
{
    int r = 0;
    while (n != 0)
    {
        int d = n % 10;
        n /= 10;
        r += d * d;
    }
    return r;
}
class OptimizeSolution
{
public:
    bool isHappy(int n)
    {
        int slow = n;
        int fast = n;
        do
        {
            slow = next_n(slow);
            fast = next_n(next_n(fast));
        } while (slow != fast);

        return fast == 1;
    }
};

//Approach : We start with the given number and maintain a set of already seen numbers.
//           Keep updating the number and check whether it is present in the set or not
//           If not, insert the number into the set and continue.
//           Else, simply return false, as it would result in a cycle.

class MySolution
{
public:
    bool isHappy(int n)
    {
        int result;
        int num = n;
        set<int> numSet;
        while (num != 1)
        {
            if (!numSet.count(num))
                numSet.insert(num);
            else
                return false;
            result = 0;
            while (num > 0)
            {
                int remainder = num % 10;
                result = result + remainder * remainder;
                num = num / 10;
            }
            num = result;
        }
        return true;
    }
};