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
    int cams = 0;

    int dfs(TreeNode *curr)
    {
        if (curr == NULL)
        {
            return 1;
        }
        int left = dfs(curr->left);
        int right = dfs(curr->right);
        if (left == 1 && right == 1)
        {
            //Both children are being monitored, but have no cameras
            //so current node is not being monitored
            return 0;
        }
        else if (left == 0 || right == 0)
        {
            //one of the children is not being monitored
            //so we add a camera at the current node
            cams++;
            return 2;
        }
        else
        {
            //current node being monitored with no cameras
            return 1;
        }
    }

    int minCameraCover(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        cams = 0;
        int res = dfs(root);
        return cams + (res == 0 ? 1 : 0);
    }
};