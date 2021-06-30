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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *prev = NULL;
        ListNode *nxt = NULL;
        ListNode *curr = head;
        stack<ListNode *> st;

        int i = 1;
        while (i != left)
        {
            prev = curr;
            curr = curr->next;
            i++;
        }

        while (i <= right)
        {
            st.push(curr);
            curr = curr->next;
            i++;
        }
        nxt = curr;

        while (!st.empty())
        {
            curr = st.top();
            st.pop();
            if (prev == NULL)
            {
                head = curr;
            }
            else
            {
                prev->next = curr;
            }
            prev = curr;
        }
        prev->next = nxt;
        return head;
    }
};