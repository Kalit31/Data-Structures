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
    TreeNode *rt;
    map<int, TreeNode *> parent;
    int l, h;
    void inorder(TreeNode *n)
    {
        if (n == NULL)
        {
            return;
        }

        if (n->val < l)
        {
            TreeNode *p = parent[n->val];
            if (p == NULL)
            {
                rt = n->right;
                n = n->right;
                if (n != NULL)
                {
                    parent[n->val] = p;
                    inorder(n);
                }
            }
            else if (p->left == n)
            {
                p->left = n->right;
                n = n->right;
                if (n != NULL)
                {
                    parent[n->val] = p;
                    inorder(n);
                }
            }
            else
            {
            }
        }
        else if (n->val > h)
        {
            TreeNode *p = parent[n->val];
            if (p == NULL)
            {
                rt = n->left;
                n = n->left;
                if (n != NULL)
                {
                    parent[n->val] = p;
                    inorder(n);
                }
            }
            else if (p->right == n)
            {
                p->right = n->left;
                n = n->left;
                if (n != NULL)
                {
                    parent[n->val] = p;
                    inorder(n);
                }
            }
        }
        else
        {
            if (n->left != NULL)
            {
                parent[n->left->val] = n;
                inorder(n->left);
            }
            if (n->right != NULL)
            {
                parent[n->right->val] = n;
                inorder(n->right);
            }
        }
    }

    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (root == NULL)
            return root;

        rt = root;
        parent[root->val] = NULL;
        l = low;
        h = high;
        inorder(root);

        return rt;
    }
};

class Solution
{
public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (!root)
            return root;
        if (root->val < low)
            return trimBST(root->right, low, high);
        if (root->val > high)
            return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};