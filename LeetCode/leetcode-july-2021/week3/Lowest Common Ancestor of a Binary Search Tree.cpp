#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *curr = root;
        if (p->val > q->val)
        {
            swap(p, q);
        }
        while (true)
        {
            if (curr == p || curr == q)
            {
                return curr;
            }
            if (curr->val > p->val && curr->val < q->val)
            {
                return curr;
            }
            if (p->val < curr->val)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        return NULL;
    }
};