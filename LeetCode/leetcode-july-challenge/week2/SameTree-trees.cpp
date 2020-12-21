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

//BFS O(n) time complexity
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
        {
            return true;
        }

        if (p == NULL || q == NULL)
        {
            return false;
        }

        queue<pair<TreeNode *, int>> qp;
        queue<pair<TreeNode *, int>> qq;

        qp.push({p, 1});
        qq.push({q, 1});

        while (!qp.empty() && !qq.empty())
        {
            auto pf = qp.front();
            qp.pop();
            auto qf = qq.front();
            qq.pop();
            if (pf.first->val != qf.first->val || pf.second != qf.second)
            {
                return false;
            }
            if (pf.first->left)
            {
                qp.push({pf.first->left, 2 * pf.second});
            }
            if (pf.first->right)
            {
                qp.push({pf.first->right, 2 * pf.second + 1});
            }
            if (qf.first->left)
            {
                qq.push({qf.first->left, 2 * qf.second});
            }
            if (qf.first->right)
            {
                qq.push({qf.first->right, 2 * qf.second + 1});
            }
        }
        if (qp.empty() && qq.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

//Recursive approach O(n) time complexity
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return 1;
        if ((!p && q) || (p && !q))
            return 0;
        if (p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else
            return 0;
    }
};