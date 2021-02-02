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
    struct custComp
    {
        bool operator()(const ListNode *l1, const ListNode *l2)
        {
            return l1->val > l2->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = NULL;
        if (lists.size() == 0)
        {
            return head;
        }
        priority_queue<ListNode *, vector<ListNode *>, custComp> q;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != NULL)
            {
                q.push(lists[i]);
            }
        }
        if (q.empty())
        {
            return head;
        }
        head = q.top();
        q.pop();
        ListNode *curr = head;
        if (curr == NULL)
        {
            return head;
        }
        if (curr->next != NULL)
        {
            q.push(curr->next);
        }
        while (!q.empty())
        {
            curr->next = q.top();
            q.pop();
            curr = curr->next;
            if (curr->next != NULL)
            {
                q.push(curr->next);
            }
        }
        return head;
    }
};