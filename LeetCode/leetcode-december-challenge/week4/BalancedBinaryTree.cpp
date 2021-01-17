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
    bool balanced = true;

    int build(TreeNode *curr)
    {
        if (curr == NULL)
        {
            return 0;
        }
        int l = build(curr->left);
        int r = build(curr->right);
        if (abs(l - r) > 1)
        {
            balanced = false;
        }
        return max(l, r) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        balanced = true;
        build(root);
        return balanced;
    }
};