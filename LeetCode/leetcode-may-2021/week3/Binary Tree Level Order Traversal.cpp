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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == NULL)
        {
            return result;
        }
        vector<int> levelNodes;
        int size = 1;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            size = q.size();
            levelNodes.clear();
            while (size--)
            {
                TreeNode *curr = q.front();
                q.pop();
                levelNodes.push_back(curr->val);
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            result.push_back(levelNodes);
        }
        return result;
    }
};