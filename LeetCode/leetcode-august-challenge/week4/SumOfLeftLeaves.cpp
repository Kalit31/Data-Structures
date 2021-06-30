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

//BFS
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

//DFS
class Solution {
public:
    
    int dfs(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        int ans = left + right;
        
        if(root->left && root->left->left == NULL && root->left->right == NULL){
            ans += root->left->val;    
        }
        return ans;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root);
    }
};
