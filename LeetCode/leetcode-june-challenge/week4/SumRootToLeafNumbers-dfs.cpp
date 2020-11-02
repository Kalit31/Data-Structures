#include <bits/stdc++.h>
using namespace std;

//Type: Trees
//Approach: We apply a dfs traversal on the root,
//          maintaing the value formed till the current node.
//          If the current node is a leaf, add it to the global sum variable,
//          else continue the traversal.

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
    int sum = 0;

    void dfs(TreeNode *root, int val)
    {

        if (!root)
        {
            return;
        }

        val = val * 10 + root->val;

        if (!root->left && !root->right)
        {
            sum = sum + val;
            return;
        }
        dfs(root->left, val);
        dfs(root->right, val);
    }

    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        dfs(root, 0);
        return sum;
    }
};