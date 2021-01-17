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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int n1 = 0;
        int n2 = 0;
        ListNode *t = l1;
        while (t != NULL)
        {
            n1++;
            t = t->next;
        }
        t = l2;
        while (t != NULL)
        {
            n2++;
            t = t->next;
        }
        if (n2 > n1)
        {
            swap(l1, l2);
        }
        ListNode *result = l1;
        int carry = 0;
        ListNode *prev = NULL;
        while (l2 != NULL)
        {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            l1->val = sum;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (carry != 0 && l1 != NULL)
        {
            l1->val = l1->val + carry;
            carry = l1->val / 10;
            l1->val = l1->val % 10;
            prev = l1;
            l1 = l1->next;
        }
        if (carry != 0)
        {
            ListNode *n = new ListNode(carry);
            prev->next = n;
            n->next = NULL;
        }
        return result;
    }
};