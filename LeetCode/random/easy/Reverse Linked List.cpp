#include <bits/stdc++.h>
using namespace std;

/**
  Definition for singly-linked list.*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//O(1) space
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }
        ListNode *prev = head;
        ListNode *curr = head->next;
        ListNode *nxt = NULL;
        prev->next = NULL;

        while (curr != NULL)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }
};

//O(N) space
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }
        stack<ListNode *> st;
        ListNode *curr = head;
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->next;
        }
        ListNode *newHead = st.top();
        st.pop();
        curr = newHead;

        while (!st.empty())
        {
            curr->next = st.top();
            curr = st.top();
            st.pop();
        }
        curr->next = NULL;
        return newHead;
    }
};