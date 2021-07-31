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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            TreeNode *newRoot = new TreeNode(val);
            return newRoot;
        }
        TreeNode *parent = NULL;
        TreeNode *curr = root;

        while (curr != NULL)
        {
            parent = curr;
            if (val < curr->val)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        TreeNode *newNode = new TreeNode(val);
        if (val < parent->val)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }
        return root;
    }
};