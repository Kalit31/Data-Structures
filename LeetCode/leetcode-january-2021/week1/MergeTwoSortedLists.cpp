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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *result = NULL;
        ListNode *res = NULL;
        while (l1 != NULL || l2 != NULL)
        {
            if (l1 != NULL && l2 != NULL)
            {
                int v1 = l1->val;
                int v2 = l2->val;
                if (v1 <= v2)
                {
                    if (res == NULL)
                    {
                        res = l1;
                        result = res;
                    }
                    else
                    {
                        result->next = l1;
                        result = result->next;
                    }
                    l1 = l1->next;
                }
                else
                {
                    if (res == NULL)
                    {
                        res = l2;
                        result = res;
                    }
                    else
                    {
                        result->next = l2;
                        result = result->next;
                    }
                    l2 = l2->next;
                }
            }
            else if (l1 != NULL)
            {
                if (res == NULL)
                {
                    res = l1;
                    result = res;
                }
                else
                {
                    result->next = l1;
                }
                return res;
            }
            else
            {
                if (res == NULL)
                {
                    res = l2;
                    result = res;
                }
                else
                {
                    result->next = l2;
                }
                return res;
            }
        }
        return res;
    }
};