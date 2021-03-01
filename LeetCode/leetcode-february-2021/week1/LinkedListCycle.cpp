#include <bits/stdc++.h>
using namespace std;
/**
  Definition for singly-linked list.*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *tort = head;
        ListNode *hare = head;
        bool flag = false;
        while (hare != NULL && hare->next != NULL)
        {
            tort = tort->next;
            hare = hare->next->next;
            if (tort == hare)
            {
                flag = true;
                break;
            }
        }
        return flag;
    }
};