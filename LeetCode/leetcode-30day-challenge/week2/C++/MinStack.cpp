#include <bits/stdc++.h>
using namespace std;

//Type: Stacks

//Approach: Maintain a main stack along with an auxillary stack.
//          Starting out, both the stacks would be empty, so simply push the element in both.
//          Next time, we find the main stack to be empty again, perform similarly.
//          The auxillary stack basically maintains the minimum elements till now.
//          So, whenever a new element is to be pushed, we compare with the top of aux st.
//          If aux top is less, than we know the current element is not the minimum, hence, only push in the main stack.
//          Else, push in both the stacks.
//          Now, for popping, if the element to be popped from main st is equal to aux top,
//          then pop from both the stacks, else only from main stack.
//          Following this implementation, we could easily get the minimum element till now, which is the top of aux st.
//Complexity: O(1) time to fetch minimum element

class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> aux_st;

    MinStack()
    {
    }

    void push(int x)
    {
        if (st.empty())
        {
            st.push(x);
            aux_st.push(x);
        }
        else if (aux_st.top() < x)
        {
            st.push(x);
        }
        else
        {
            st.push(x);
            aux_st.push(x);
        }
    }

    void pop()
    {
        if (st.top() == aux_st.top())
        {
            st.pop();
            aux_st.pop();
        }
        else
        {
            st.pop();
        }
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return aux_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */