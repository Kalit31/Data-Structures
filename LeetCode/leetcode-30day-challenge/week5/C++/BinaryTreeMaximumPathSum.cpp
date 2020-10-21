#include <bits/stdc++.h>
using namespace std;

//Type: Trees
//Approach: Maintain a global max-path variable.
//          At each node, find the maxPathSum in left child and right child.
//          If any of the subtree path is negative, it would be better to not take it
//          Now, update the max-path varaible if value of current node + its subtree path sum is greater
//          Return the maximum path sum among the subtrees in addition to the current value in each fn call.
//Complexity: O(number of nodes) time

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
    int maxPath = INT_MIN;
    int maxPathSum(TreeNode *root)
    {
        calc(root);
        return maxPath;
    }
    int calc(TreeNode *n)
    {
        if (n == NULL)
        {
            return 0;
        }
        int l = max(0, calc(n->left));
        int r = max(0, calc(n->right));
        maxPath = max(maxPath, n->val + l + r);
        return n->val + max(l, r);
    }
};