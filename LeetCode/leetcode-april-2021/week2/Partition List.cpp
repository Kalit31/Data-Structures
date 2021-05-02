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
    ListNode *partition(ListNode *head, int x)
    {

        if (head == NULL)
        {
            return head;
        }

        ListNode *h1 = NULL;
        ListNode *h2 = NULL;
        ListNode *curr1 = NULL;
        ListNode *curr2 = NULL;

        ListNode *curr = head;
        ListNode *next = NULL;

        while (curr)
        {
            next = curr->next;
            curr->next = NULL;
            if (curr->val >= x)
            {
                if (h2 == NULL)
                {
                    h2 = curr;
                    curr2 = h2;
                }
                else
                {
                    curr2->next = curr;
                    curr2 = curr2->next;
                }
            }
            else
            {
                if (h1 == NULL)
                {
                    h1 = curr;
                    curr1 = h1;
                }
                else
                {
                    curr1->next = curr;
                    curr1 = curr1->next;
                }
            }
            curr = next;
        }
        if (curr1 == NULL)
        {
            //all elements greater than x
            h1 = h2;
        }
        else
        {
            curr1->next = h2;
        }
        if (curr2 == NULL)
        {
            //all elements less than x
            curr1->next = NULL;
        }
        else
        {
            curr2->next = NULL;
        }
        return h1;
    }
};