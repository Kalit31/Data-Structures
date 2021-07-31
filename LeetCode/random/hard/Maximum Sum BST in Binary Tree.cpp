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
    int ans = 0;

    //return {sum,max,min}
    array<int, 3> build(TreeNode *curr)
    {
        if (curr == NULL)
        {
            return {0, INT_MIN, INT_MAX};
        }
        array<int, 3> left = build(curr->left);
        array<int, 3> right = build(curr->right);

        if (left[0] == INT_MAX || right[0] == INT_MAX)
        {
            //either of the child subtrees are not valid BSTs, the new BST would also be not valid;
            return {INT_MAX, INT_MIN, INT_MAX};
        }
        //if the max in the left subtree is greater than curr val, BST not valid
        if (left[1] >= curr->val)
        {
            return {INT_MAX, INT_MIN, INT_MAX};
        }
        //if the min in the right subtree is smaller than curr val, BST not valid
        if (right[2] <= curr->val)
        {
            return {INT_MAX, INT_MIN, INT_MAX};
        }

        //BST is valid
        int sum = left[0] + curr->val + right[0];
        ans = max(ans, sum);

        int minVal = min(curr->val, left[2]);
        int maxVal = max(curr->val, right[1]);

        return {sum, maxVal, minVal};
    }

    int maxSumBST(TreeNode *root)
    {
        build(root);
        return ans;
    }
};