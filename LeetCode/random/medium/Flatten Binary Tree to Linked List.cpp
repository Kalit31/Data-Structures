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
    void flatten(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        TreeNode *curr = root;
        while (curr)
        {
            if (curr->left)
            {
                TreeNode *next = curr->left;
                while (next->right)
                {
                    next = next->right;
                }
                next->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};