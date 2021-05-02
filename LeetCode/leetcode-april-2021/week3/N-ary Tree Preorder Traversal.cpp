#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
*/
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

//Iterative
class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> result;
        if (root == NULL)
        {
            return result;
        }

        stack<Node *> st;
        st.push(root);

        while (!st.empty())
        {
            Node *curr = st.top();
            st.pop();

            result.push_back(curr->val);

            for (int i = (curr->children).size() - 1; i >= 0; i--)
            {
                st.push((curr->children)[i]);
            }
        }

        return result;
    }
};

//Recursive
class Solution
{
public:
    vector<int> result;

    void build(Node *curr)
    {
        if (curr == NULL)
        {
            return;
        }

        result.push_back(curr->val);

        for (Node *child : curr->children)
        {
            build(child);
        }
    }

    vector<int> preorder(Node *root)
    {
        result.clear();

        build(root);

        return result;
    }
};