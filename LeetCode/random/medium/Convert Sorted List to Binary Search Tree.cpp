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

/**
 * Definition for a binary tree node.*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *build(vector<TreeNode *> nodes, int l, int r)
    {
        if (l > r)
        {
            return NULL;
        }
        int mid = l + (r - l) / 2;
        TreeNode *root = nodes[mid];
        root->left = build(nodes, l, mid - 1);
        root->right = build(nodes, mid + 1, r);
        return root;
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        vector<TreeNode *> nodes;
        while (head != NULL)
        {
            TreeNode *tn = new TreeNode(head->val);
            nodes.push_back(tn);
            head = head->next;
        }
        TreeNode *root = build(nodes, 0, nodes.size() - 1);
        return root;
    }
};