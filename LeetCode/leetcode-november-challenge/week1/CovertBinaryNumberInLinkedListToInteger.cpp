#include <bits/stdc++.h>
using namespace std;

//Type: LinkedLists
//Approach: Initialize the result variable to '0'.
//          Start iterating through the list.
//          At each node, multiply the result by 2 and add the value of the current node to it.

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
    int getDecimalValue(ListNode *head)
    {
        int result = 0;
        ListNode *curr = head;
        while (curr != NULL)
        {
            result = result * 2 + curr->val;
            curr = curr->next;
        }
        return result;
    }
};