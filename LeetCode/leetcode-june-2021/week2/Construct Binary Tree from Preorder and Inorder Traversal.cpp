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
    int ind = 0;

    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int l, int r)
    {
        if (l > r)
        {
            return NULL;
        }
        int val = preorder[ind++];
        int i = l;
        //can use a map to find the appropriate index, instead of iterating
        while (inorder[i] != val)
        {
            i++;
        }
        TreeNode *root = new TreeNode(val);
        root->left = build(preorder, inorder, l, i - 1);
        root->right = build(preorder, inorder, i + 1, r);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        ind = 0;
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};