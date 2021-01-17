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
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        if (target == NULL)
        {
            return NULL;
        }
        int val = target->val;
        queue<TreeNode *> q;
        q.push(cloned);
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->val == val)
            {
                return curr;
            }
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        return NULL;
    }
};