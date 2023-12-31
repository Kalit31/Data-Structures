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
    TreeNode *build(vector<int> &nums, int l, int r)
    {
        if (l == r)
        {
            TreeNode *child = new TreeNode(nums[l]);
            return child;
        }
        int mid = (l + r) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        if (mid - 1 >= l)
            root->left = build(nums, l, mid - 1);
        if (mid + 1 <= r)
            root->right = build(nums, mid + 1, r);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return build(nums, 0, nums.size() - 1);
    }
};