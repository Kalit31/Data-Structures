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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    int len = 0;
    ListNode *headPtr;
    Solution(ListNode *head)
    {
        len = 0;
        headPtr = head;
        ListNode *t = head;
        while (t != NULL)
        {
            len++;
            t = t->next;
        }
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        int idx = rand() % len;
        int i = -1;
        ListNode *t = headPtr;
        int result;
        do
        {
            result = t->val;
            t = t->next;
            i++;
        } while (i != idx);
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */