#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool buildPath(TreeNode *curr, vector<TreeNode *> &path, vector<TreeNode *> &main, int val)
    {
        path.push_back(curr);
        if (curr->val == val)
        {
            main = path;
            return true;
        }
        if (curr->left)
        {
            if (buildPath(curr->left, path, main, val))
            {
                return true;
            }
        }
        if (curr->right)
        {
            if (buildPath(curr->right, path, main, val))
            {
                return true;
            }
        }
        path.pop_back();
        return false;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> path;
        vector<TreeNode *> pPath, qPath;
        buildPath(root, path, pPath, p->val);
        path.clear();
        buildPath(root, path, qPath, q->val);

        int i = 0;
        int j = 0;

        while (i < pPath.size() && j < qPath.size() && pPath[i]->val == qPath[j]->val)
        {
            i++;
            j++;
        }
        return pPath[i - 1];
    }
};