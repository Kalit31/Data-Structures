#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for binary tree*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Iteartive, traversing through each node(slow)
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        int ans = 0;
        if (root == NULL)
        {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->left != NULL)
            {
                TreeNode *child = curr->left;
                if (child->left == NULL && child->right == NULL)
                {
                    ans += child->val;
                }
            }
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        return ans;
    }
};

//Recursive fast
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        if (root->left == NULL && root->right == NULL)
        {
            return 0;
        }

        int v1 = sumOfLeftLeaves(root->left);
        int v2 = sumOfLeftLeaves(root->right);

        if (root->left)
        {
            TreeNode *node = root->left;
            if (node->left == NULL && node->right == NULL)
            {
                return v1 + v2 + root->left->val;
            }
        }

        return v1 + v2;
    }
};