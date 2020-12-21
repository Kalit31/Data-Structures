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
    TreeNode *findSuccessor(TreeNode *root)
    {
        TreeNode *curr = root->right;
        if (curr == NULL)
        {
            return curr;
        }
        while (curr->left != NULL)
        {
            curr = curr->left;
        }
        return curr;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
        {
            return root;
        }
        if (root->val == key)
        {
            TreeNode *succ = findSuccessor(root);
            if (succ == NULL)
            {
                return root->left;
            }
            int val = root->val;
            root->val = succ->val;
            succ->val = val;
            return deleteNode(root, val);
        }
        TreeNode *curr = root;
        TreeNode *nodeToRemove = NULL;
        bool left = false;
        queue<TreeNode *> q;
        q.push(curr);
        while (!q.empty())
        {
            curr = q.front();
            q.pop();
            if (curr->left)
            {
                if (curr->left->val == key)
                {
                    nodeToRemove = curr->left;
                    left = true;
                    break;
                }
                q.push(curr->left);
            }
            if (curr->right)
            {
                if (curr->right->val == key)
                {
                    nodeToRemove = curr->right;
                    break;
                }
                q.push(curr->right);
            }
        }
        if (nodeToRemove == NULL)
        {
            return root;
        }

        if (nodeToRemove->left == NULL && nodeToRemove->right == NULL)
        {
            if (left)
            {
                curr->left = NULL;
            }
            else
            {
                curr->right = NULL;
            }
            return root;
        }
        TreeNode *succ = findSuccessor(nodeToRemove);
        if (succ == NULL)
        {
            if (left)
            {
                curr->left = nodeToRemove->left;
            }
            else
            {
                curr->right = nodeToRemove->left;
            }
            return root;
        }
        int val = nodeToRemove->val;
        nodeToRemove->val = succ->val;
        succ->val = val;
        return deleteNode(root, val);
    }
};