#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    /** initialize your data structure here. */
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median;

    MedianFinder()
    {
        median = -1;
    }

    void addNum(int num)
    {
        if (maxHeap.empty())
        {
            maxHeap.push(num);
            median = num;
        }
        else
        {
            if (maxHeap.size() > minHeap.size())
            {
                if (num < median)
                {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(num);
                }
                else
                {
                    minHeap.push(num);
                }
                median = (maxHeap.top() + minHeap.top()) / 2.0;
            }
            else if (maxHeap.size() == minHeap.size())
            {
                if (num < median)
                {
                    maxHeap.push(num);
                    median = maxHeap.top();
                }
                else
                {
                    minHeap.push(num);
                    median = minHeap.top();
                }
            }
            else
            {
                if (num > median)
                {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(num);
                }
                else
                {
                    maxHeap.push(num);
                }
                median = (maxHeap.top() + minHeap.top()) / 2.0;
            }
        }
    }

    double findMedian()
    {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */