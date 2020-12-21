#include <bits/stdc++.h>
using namespace std;

/*
Definition for a Node.*/
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        stack<Node *> st;
        Node *curr = head;
        while (curr != NULL)
        {

            if (curr->child != NULL)
            {
                if (curr->next != NULL)
                    st.push(curr->next);
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = NULL;
            }

            if (curr->next == NULL && !st.empty())
            {
                Node *n = st.top();
                st.pop();
                curr->next = n;
                n->prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        Node *ptr = head;
        while (ptr)
        {
            if (ptr->child != nullptr)
            {
                auto temp = ptr->next;
                auto temp2 = ptr;
                ptr->next = flatten(ptr->child);
                if (ptr->next)
                {
                    ptr->next->prev = temp2;
                }
                ptr->child = nullptr;
                while (ptr && ptr->next)
                    ptr = ptr->next;
                ptr->next = temp;
                if (temp)
                {
                    temp->prev = ptr;
                }
            }
            ptr = ptr->next;
        }
    }
};