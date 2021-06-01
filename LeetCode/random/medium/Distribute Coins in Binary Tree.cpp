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
    int moves = 0;

    int dfs(TreeNode *curr)
    {
        if (curr == NULL)
        {
            return 0;
        }
        int left = dfs(curr->left);
        int right = dfs(curr->right);
        moves += abs(left) + abs(right);
        return curr->val + left + right - 1;
    }

    int distributeCoins(TreeNode *root)
    {
        moves = 0;
        dfs(root);
        return moves;
    }
};