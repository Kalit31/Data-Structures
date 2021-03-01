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

int calcLen(ListNode *curr)
{
    int len1 = 0;
    while (curr)
    {
        curr = curr->next;
        len1++;
    }
    return len1;
}

void swapNodes(ListNode *l1, ListNode *l2)
{
    ListNode *t = l1;
    l1 = l2;
    l2 = t;
}

void populateStack(stack<ListNode *> &s, ListNode *curr)
{
    while (curr)
    {
        s.push(curr);
        curr = curr->next;
    }
}

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *curr = l1;
        int len1 = calcLen(curr);
        curr = l2;
        int len2 = calcLen(curr);

        if (len2 > len1)
            swapNodes(l1, l2);

        stack<ListNode *> s1, s2;
        curr = l1;
        populateStack(s1, curr);
        curr = l2;
        populateStack(s2, curr);

        int carry = 0;
        while (!s2.empty())
        {
            ListNode *tl1 = s1.top();
            s1.pop();
            ListNode *tl2 = s2.top();
            s2.pop();
            tl1->val = tl1->val + tl2->val + carry;
            carry = (tl1->val) / 10;
            tl1->val = (tl1->val) % 10;
            cout << tl1->val << endl;
        }
        while (carry)
        {
            if (!s1.empty())
            {
                ListNode *l = s1.top();
                s1.pop();
                l->val = l->val + carry;
                carry = (l->val) / 10;
                l->val = (l->val) % 10;
            }
            else
            {
                ListNode *l = new ListNode(carry);
                l->next = l1;
                return l;
            }
        }
        return l1;
    }
};