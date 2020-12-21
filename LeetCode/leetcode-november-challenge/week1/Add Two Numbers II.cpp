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
        int len1 = 0;
        int len2 = 0;
        ListNode *tl1 = l1;
        ListNode *tl2 = l2;
        while (tl1 != NULL)
        {
            tl1 = tl1->next;
            len1++;
        }
        while (tl2 != NULL)
        {
            tl2 = tl2->next;
            len2++;
        }
        if (len2 > len1)
        {
            ListNode *t = l1;
            l1 = l2;
            l2 = t;
        }
        stack<ListNode *> s1, s2;
        tl1 = l1;
        tl2 = l2;
        while (tl1 != NULL)
        {
            s1.push(tl1);
            tl1 = tl1->next;
        }
        while (tl2 != NULL)
        {
            s2.push(tl2);
            tl2 = tl2->next;
        }
        int carry = 0;

        //cout<<"Len1: "<<len1<<endl;
        //cout<<"Len2: "<<len2<<endl;
        while (!s1.empty() && !s2.empty())
        {
            tl1 = s1.top();
            s1.pop();
            //cout<<"L1: "<<tl1->val<<endl;
            tl2 = s2.top();
            s2.pop();
            //cout<<"L2: "<<tl2->val<<endl;
            tl1->val = tl1->val + tl2->val + carry;
            carry = tl1->val / 10;
            tl1->val = tl1->val % 10;
        }
        if (carry != 0)
        {
            while (!s1.empty() && carry != 0)
            {
                tl1 = s1.top();
                s1.pop();
                tl1->val = tl1->val + carry;
                carry = tl1->val / 10;
                tl1->val = tl1->val % 10;
            }
            if (carry == 0)
            {
                return l1;
            }
            ListNode *newNode = new ListNode();
            newNode->val = carry;
            newNode->next = l1;
            l1 = newNode;
        }
        return l1;
    }
};