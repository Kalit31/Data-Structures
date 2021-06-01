#include <bits/stdc++.h>
using namespace std;

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
    int maxLen = 1;
    int longestUnivaluePath(TreeNode *root)
    {
        maxLen = 1;
        if (root == NULL)
        {
            return 0;
        }
        build(root);
        return maxLen - 1;
    }

    int build(TreeNode *curr)
    {
        if (curr == NULL)
        {
            return 0;
        }
        int currLen = 1;
        int len = 1;
        int left = build(curr->left);
        if (curr->left)
        {
            if (curr->left->val == curr->val)
            {
                currLen = max(currLen, 1 + left);
                len = currLen;
            }
        }
        int right = build(curr->right);
        if (curr->right)
        {
            if (curr->right->val == curr->val)
            {
                currLen = max(currLen, 1 + right);
                len = currLen;
            }
        }
        if (curr->left && curr->right)
        {
            if (curr->val == curr->left->val && curr->left->val == curr->right->val)
            {
                currLen = max(currLen, 1 + left + right);
            }
        }
        maxLen = max(maxLen, currLen);
        return len;
    }
};