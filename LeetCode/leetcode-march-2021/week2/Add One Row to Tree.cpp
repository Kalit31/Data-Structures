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
    TreeNode *addOneRow(TreeNode *root, int v, int d)
    {
        if (d == 1)
        {
            TreeNode *newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        queue<TreeNode *> q;
        q.push(root);
        map<int, vector<TreeNode *>> mp;
        int depth = 1;
        int sz = q.size();
        while (!q.empty())
        {
            if (sz == 0)
            {
                sz = q.size();
                depth++;
                if (depth == d)
                {
                    break;
                }
            }
            TreeNode *curr = q.front();
            q.pop();
            mp[depth].push_back(curr);
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
            sz--;
        }
        vector<TreeNode *> nodes = mp[d - 1];
        for (int i = 0; i < nodes.size(); i++)
        {
            TreeNode *curr = nodes[i];
            TreeNode *l = curr->left;
            TreeNode *r = curr->right;
            curr->left = new TreeNode(v);
            curr->left->left = l;
            curr->right = new TreeNode(v);
            curr->right->right = r;
        }
        return root;
    }
};