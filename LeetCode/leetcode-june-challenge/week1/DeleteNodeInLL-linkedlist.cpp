#include <bits/stdc++.h>
using namespace std;

//Type: LinkedLists
//Approach: We have been given the reference to the node we want to delete
//          and not any other ptr to head or so.
//          So, the basic idea is to keep copying the value in the next node
//          into the current node or keep bubbling up the value(in the node to be deleted)
//          to the end. Then, simply delete the last node.
//Complexity: O(N) time and O(1) space

/**
 * Definition for singly-linked list.*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *curr = node;
        while (curr != NULL)
        {
            if (curr->next != NULL)
            {
                curr->val = curr->next->val;
            }
            if (curr->next->next == NULL)
            {
                curr->next = NULL;
                break;
            }
            curr = curr->next;
        }
    }
};