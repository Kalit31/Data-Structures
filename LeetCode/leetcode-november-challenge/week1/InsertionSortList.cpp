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
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;
        while (curr != NULL)
        {
            ListNode *temp = head;
            ListNode *tPrev = NULL;
            if (curr != head)
            {
                while (temp != curr && temp->val < curr->val)
                {
                    tPrev = temp;
                    temp = temp->next;
                }
                if (temp == curr)
                {
                    prev = curr;
                    curr = curr->next;
                }
                else
                {
                    if (tPrev == NULL)
                    {
                        head = curr;
                        prev->next = curr->next;
                        curr->next = temp;
                        curr = prev->next;
                    }
                    else
                    {
                        prev->next = curr->next;
                        tPrev->next = curr;
                        curr->next = temp;
                        curr = prev->next;
                    }
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};