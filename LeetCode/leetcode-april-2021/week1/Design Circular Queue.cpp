#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue
{
public:
    vector<int> q;
    int first, last;
    int qSize;
    int cnt;

    MyCircularQueue(int k)
    {
        q.clear();
        q.resize(k, -1);
        first = 0;
        last = -1;
        qSize = k;
        cnt = 0;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        last++;
        last = last % qSize;
        q[last] = value;
        cnt++;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        first++;
        first = first % qSize;
        cnt--;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;

        return q[first];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;

        return q[last];
    }

    bool isEmpty()
    {
        return cnt == 0;
    }

    bool isFull()
    {
        return cnt == qSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */