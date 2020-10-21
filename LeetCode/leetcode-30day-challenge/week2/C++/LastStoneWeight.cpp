#include <bits/stdc++.h>
using namespace std;

//Type: Maximum Heaps

//Approach: Push all the stone weights in the max-heap.
//          Start popping out the heavy stones. Perform operations accordingly.
//Complexity: O(NlgN) time complexity Creation and Updation of Heap, O(N) space complexity

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> queue;
        for (int s : stones)
        {
            queue.push(s);
        }
        while (queue.size() > 1)
        {
            int s1 = queue.top();
            queue.pop();
            int s2 = queue.top();
            queue.pop();
            if (s1 != s2)
            {
                queue.push(s1 - s2);
            }
        }

        return queue.empty() ? 0 : queue.top();
    }
};