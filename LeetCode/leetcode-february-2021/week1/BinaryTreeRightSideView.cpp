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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        if (root == NULL)
        {
            return result;
        }

        queue<TreeNode *> q;
        q.push(root);
        int genPop = 1;

        result.push_back(root->val);

        while (!q.empty())
        {
            if (genPop == 0)
            {
                result.push_back((q.back())->val);
                genPop = q.size();
            }
            TreeNode *n = q.front();
            q.pop();

            if (n->left != NULL)
            {
                q.push(n->left);
            }

            if (n->right != NULL)
            {
                q.push(n->right);
            }
            genPop--;
        }
        return result;
    }
};