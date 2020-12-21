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
    vector<int> q;

    void build(TreeNode *curr)
    {
        if (curr == NULL)
        {
            return;
        }
        build(curr->left);
        q.push_back(curr->val);
        build(curr->right);
    }

    bool isValidBST(TreeNode *root)
    {
        q.clear();
        build(root);
        for (int i = 1; i < q.size(); i++)
        {
            if (q[i] <= q[i - 1])
            {
                return false;
            }
        }
        return true;
    }
};