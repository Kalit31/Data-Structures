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

// Two Pass soln
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *curr = head;
        int len = 0;
        while (curr != NULL)
        {
            curr = curr->next;
            len++;
        }
        curr = head;
        ListNode *prev = NULL;

        int pos = 1;
        while (curr != NULL)
        {
            if (pos == (len - n + 1))
            {
                if (prev == NULL)
                {
                    head = head->next;
                }
                else
                {
                    prev->next = curr->next;
                }
                break;
            }
            else
            {
                prev = curr;
                curr = curr->next;
                pos++;
            }
        }
        return head;
    }
};

// Single Pass soln
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *first = dummy;
        ListNode *second = dummy;

        for (int i = 1; i <= n + 1; i++)
        {
            first = first->next;
        }

        while (first != NULL)
        {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;

        return dummy->next;
    }
};