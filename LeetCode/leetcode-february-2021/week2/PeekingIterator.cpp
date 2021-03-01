#include <bits/stdc++.h>
using namespace std;
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.*/

class Iterator
{
public:
    struct Data;
    Data *data;
    Iterator(const vector<int> &nums);
    Iterator(const Iterator &iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator
{
public:
    bool nextFilled = false;
    int nextNum = 0;
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        nextFilled = false;
        nextNum = 0;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek()
    {
        if (nextFilled)
        {
            return nextNum;
        }
        else
        {
            nextNum = Iterator::next();
            nextFilled = true;
            return nextNum;
        }
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next()
    {
        if (nextFilled)
        {
            nextFilled = false;
            return nextNum;
        }
        else
        {
            int num = Iterator::next();
            return num;
        }
    }

    bool hasNext() const
    {
        if (nextFilled)
        {
            return true;
        }
        else
        {
            return Iterator::hasNext();
        }
    }
};