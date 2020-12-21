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
    void reorderList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }
        stack<ListNode *> st;
        ListNode *curr = head;
        int cnt = 0;
        while (curr)
        {
            st.push(curr);
            curr = curr->next;
            cnt++;
        }
        int half = cnt / 2;
        curr = head;
        ListNode *nxt = NULL;
        while (half != 0)
        {
            nxt = curr->next;
            ListNode *n = st.top();
            st.pop();
            curr->next = n;
            n->next = nxt;
            curr = nxt;
            half--;
        }
        curr->next = NULL;
    }
};