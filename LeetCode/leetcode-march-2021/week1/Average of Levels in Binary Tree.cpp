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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ans;
        double sum = 0;
        queue<TreeNode *> q;
        q.push(root);
        int nodes = 0;
        int size = q.size();

        while (!q.empty())
        {
            if (size == 0)
            {
                size = q.size();
                ans.push_back((1.0 * sum) / nodes);
                nodes = 0;
                sum = 0;
            }
            TreeNode *curr = q.front();
            q.pop();
            sum += curr->val;
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
            size--;
            nodes++;
        }
        if (nodes != 0)
        {
            ans.push_back((1.0) * sum / nodes);
        }
        return ans;
    }
};