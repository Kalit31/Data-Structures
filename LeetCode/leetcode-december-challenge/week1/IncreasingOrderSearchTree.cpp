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
    queue<TreeNode *> qt;

public:
    TreeNode *increasingBST(TreeNode *root)
    {
        traverse(root);

        TreeNode *head = NULL;
        if (qt.size() > 0)
        {
            head = qt.front();
            qt.pop();

            TreeNode *p = head;

            while (!qt.empty())
            {
                p->left = NULL;
                p->right = qt.front();
                qt.pop();
                p = p->right;
            }

            p->left = NULL;
            p->right = NULL;
        }

        return head;
    }

    void traverse(TreeNode *node)
    {
        if (node == NULL)
            return;

        if (node->left != NULL)
            traverse(node->left);
        qt.push(node);
        if (node->right != NULL)
            traverse(node->right);
    }
};

class Solution
{
public:
    TreeNode *increasingBST(TreeNode *root)
    {
        map<int, TreeNode *> m;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            m[curr->val] = curr;
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
        TreeNode *result = NULL;
        TreeNode *t = NULL;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (result == NULL)
            {
                result = it->second;
                t = result;
                result->left = NULL;
                result->right = NULL;
            }
            else
            {
                result->left = NULL;
                result->right = it->second;
                result = result->right;
                result->left = NULL;
                result->right = NULL;
            }
        }
        return t;
    }
};