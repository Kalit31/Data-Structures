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
    int maxDepth = 0;

    void dfs(TreeNode *curr, int currDepth)
    {
        if (curr->left == NULL && curr->right == NULL)
        {
            maxDepth = max(maxDepth, currDepth);
        }
        if (curr->left)
        {
            dfs(curr->left, currDepth + 1);
        }
        if (curr->right)
        {
            dfs(curr->right, currDepth + 1);
        }
    }

    int sum = 0;

    void dfs2(TreeNode *curr, int currDepth)
    {
        if (currDepth == maxDepth)
        {
            sum += curr->val;
            return;
        }
        if (curr->left)
        {
            dfs2(curr->left, currDepth + 1);
        }
        if (curr->right)
        {
            dfs2(curr->right, currDepth + 1);
        }
    }

    int deepestLeavesSum(TreeNode *root)
    {
        dfs(root, 0);
        dfs2(root, 0);
        return sum;
    }
};