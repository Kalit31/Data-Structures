#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.*/
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        Node *newHead = new Node(head->val);
        map<Node *, Node *> m;

        m[head] = newHead;

        Node *nCurr = newHead;
        Node *curr = head->next;

        while (curr != NULL)
        {
            Node *newNode = new Node(curr->val);
            nCurr->next = newNode;
            nCurr = nCurr->next;
            m[curr] = newNode;
            curr = curr->next;
        }

        curr = head;
        nCurr = newHead;

        while (curr != NULL)
        {
            Node *randm = curr->random;
            if (randm != NULL)
            {
                nCurr->random = m[randm];
            }
            curr = curr->next;
            nCurr = nCurr->next;
        }

        return newHead;
    }
};