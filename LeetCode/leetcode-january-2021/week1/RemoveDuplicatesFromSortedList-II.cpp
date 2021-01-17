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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;
        while (curr)
        {
            if (curr->next)
            {
                ListNode *next = curr->next;
                if (curr->val == next->val)
                {
                    int removeVal = curr->val;
                    if (curr == head)
                    {
                        while (curr && curr->val == removeVal)
                        {
                            prev = curr;
                            curr = curr->next;
                        }
                        head = curr;
                    }
                    else
                    {
                        while (curr && curr->val == removeVal)
                        {
                            curr = curr->next;
                        }
                        prev->next = curr;
                    }
                }
                else
                {
                    prev = curr;
                    curr = curr->next;
                }
            }
            else
            {
                curr = curr->next;
            }
        }
        return head;
    }
};