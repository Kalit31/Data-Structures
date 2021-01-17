#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }
        ListNode *tailA = headA;
        ListNode *tailB = headB;

        int lA = 0;
        int lB = 0;

        while (tailA->next != NULL)
        {
            tailA = tailA->next;
            lA++;
        }
        while (tailB->next != NULL)
        {
            tailB = tailB->next;
            lB++;
        }

        if (tailA != tailB)
        {
            return NULL;
        }
        int diff = 0;

        if (lA > lB)
        {
            tailA = headA;
            tailB = headB;
            diff = lA - lB;
        }
        else
        {
            tailA = headB;
            tailB = headA;
            diff = lB - lA;
        }

        while (diff > 0)
        {
            tailA = tailA->next;
            diff--;
        }
        while (tailA != tailB)
        {
            tailA = tailA->next;
            tailB = tailB->next;
        }

        return tailA;
    }
};