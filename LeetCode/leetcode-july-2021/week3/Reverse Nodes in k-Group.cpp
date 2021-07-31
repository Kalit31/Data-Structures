#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        stack<ListNode *> st;
        ListNode *curr = head;
        ListNode *last = dummy;
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->next;
            if (st.size() == k)
            {
                while (!st.empty())
                {
                    last->next = st.top();
                    st.pop();
                    last = last->next;
                }
            }
        }
        stack<ListNode *> st2;
        while (!st.empty())
        {
            st2.push(st.top());
            st.pop();
        }
        while (!st2.empty())
        {
            last->next = st2.top();
            st2.pop();
            last = last->next;
        }
        last->next = NULL;
        return dummy->next;
    }
};