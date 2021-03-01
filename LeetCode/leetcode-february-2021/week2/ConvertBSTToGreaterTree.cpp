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
    int curr = 0;
    void build(TreeNode *node)
    {
        if (node == NULL)
        {
            return;
        }
        build(node->right);
        node->val = node->val + curr;
        curr = node->val;
        build(node->left);
    }

    TreeNode *convertBST(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        build(root);
        return root;
    }
};