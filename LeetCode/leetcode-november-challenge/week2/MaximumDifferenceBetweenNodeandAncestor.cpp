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
    int diff = 0;
    pair<int, int> build(TreeNode *curr)
    {
        pair<int, int> p1, p2;
        int max1 = curr->val;
        int min1 = curr->val;
        if (curr->left != NULL)
        {
            p1 = build(curr->left);
            max1 = max(max1, p1.first);
            min1 = min(min1, p1.second);
        }
        if (curr->right != NULL)
        {
            p2 = build(curr->right);
            max1 = max(max1, p2.first);
            min1 = min(min1, p2.second);
        }
        diff = max(diff, max(abs(curr->val - max1), abs(curr->val - min1)));
        return {max1, min1};
    }

    int maxAncestorDiff(TreeNode *root)
    {
        build(root);
        return diff;
    }
};