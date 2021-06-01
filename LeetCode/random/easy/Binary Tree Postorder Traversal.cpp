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

//Recursive soln
class Solution
{
public:
    vector<int> result;

    void build(TreeNode *curr)
    {
        if (curr == NULL)
        {
            return;
        }
        build(curr->left);
        build(curr->right);
        result.push_back(curr->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        result.clear();
        build(root);
        return result;
    }
};

//Iterative version
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;

        if (root == NULL)
        {
            return result;
        }

        stack<TreeNode *> s1, s2;
        s1.push(root);

        while (!s1.empty())
        {
            TreeNode *curr = s1.top();
            s1.pop();

            s2.push(curr);
            if (curr->left)
            {
                s1.push(curr->left);
            }
            if (curr->right)
            {
                s1.push(curr->right);
            }
        }

        while (!s2.empty())
        {
            result.push_back(s2.top()->val);
            s2.pop();
        }

        return result;
    }
};
