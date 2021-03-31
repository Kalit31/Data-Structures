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
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *curr = head;
        int len = 1;
        while (curr)
        {
            curr = curr->next;
            len++;
        }
        ListNode *a = head;
        ListNode *b = head;
        int ind1 = min(k, len - k);
        int ind2 = max(k, len - k);
        curr = head;
        int i = 1;
        while (curr)
        {
            if (i == ind1 && i == ind2)
            {
                a = curr;
                b = curr;
                break;
            }
            else if (i == ind1)
            {
                a = curr;
            }
            else if (i == ind2)
            {
                b = curr;
                break;
            }
            i++;
            curr = curr->next;
        }

        swap(a->val, b->val);
        return head;
    }
};