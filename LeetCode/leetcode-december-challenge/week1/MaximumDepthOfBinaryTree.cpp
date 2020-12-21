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
    int depth = 0;

    int build(TreeNode *curr)
    {
        if (curr == NULL)
        {
            return 0;
        }
        int leftDepth = build(curr->left);
        int rightDepth = build(curr->right);
        depth = max(depth, max(leftDepth, rightDepth) + 1);
        return (max(leftDepth, rightDepth) + 1);
    }

    int maxDepth(TreeNode *root)
    {
        build(root);
        return depth;
    }
};