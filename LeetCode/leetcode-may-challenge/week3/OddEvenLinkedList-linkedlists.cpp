#include <bits/stdc++.h>
using namespace std;

//Type: Linked List
//Approach: implementation
//Complexity: O(Nodes) time and O(1) space

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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *oddHead = head;
        ListNode *evenHead = head->next;
        ListNode *tevenHead = head->next;

        while (oddHead->next != NULL && evenHead->next != NULL)
        {
            oddHead->next = evenHead->next;
            oddHead = oddHead->next;
            evenHead->next = oddHead->next;
            evenHead = evenHead->next;
        }
        oddHead->next = tevenHead;
        return head;
    }
};

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *even = NULL;
        ListNode *curr = head;
        int i = 1;

        if (NULL == head)
            return NULL;
        ListNode *prevOdd = NULL;
        ListNode *prevEven = NULL;
        while (curr)
        {
            ListNode *next = curr->next;

            if (i % 2 == 1)
            {
                if (prevOdd)
                    prevOdd->next = curr;
                prevOdd = curr;
                curr->next = NULL;
            }
            else
            {
                if (even == NULL)
                    even = curr;
                if (prevEven)
                    prevEven->next = curr;
                prevEven = curr;
                curr->next = NULL;
            }
            i++;
            curr = next;
        }
        prevOdd->next = even;
        return head;
    }
};