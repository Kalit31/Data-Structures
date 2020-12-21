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
    int tiltSum = 0;

    int build(TreeNode *curr)
    {
        if (curr == NULL)
        {
            return 0;
        }
        int sumLeft = build(curr->left);
        int sumRight = build(curr->right);
        tiltSum += abs(sumRight - sumLeft);
        return curr->val + sumLeft + sumRight;
    }

    int findTilt(TreeNode *root)
    {
        build(root);
        return tiltSum;
    }
};