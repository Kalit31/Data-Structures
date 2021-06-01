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
    const int N = 505;

    map<int, TreeNode *> nodes;
    map<int, TreeNode *> parent;

    void dfs(TreeNode *curr)
    {
        nodes[curr->val] = curr;
        if (curr->left)
        {
            parent[curr->left->val] = curr;
            dfs(curr->left);
        }
        if (curr->right)
        {
            parent[curr->right->val] = curr;
            dfs(curr->right);
        }
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> result;

        vector<int> dist(N, -1);

        dfs(root);

        queue<TreeNode *> q;
        q.push(nodes[target->val]);
        dist[target->val] = 0;

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (dist[curr->val] == k)
            {
                result.push_back(curr->val);
            }
            if (curr->left)
            {
                if (dist[curr->left->val] == -1)
                {
                    dist[curr->left->val] = dist[curr->val] + 1;
                    q.push(curr->left);
                }
            }
            if (curr->right)
            {
                if (dist[curr->right->val] == -1)
                {
                    dist[curr->right->val] = dist[curr->val] + 1;
                    q.push(curr->right);
                }
            }
            if (parent.find(curr->val) != parent.end())
            {
                if (dist[parent[curr->val]->val] == -1)
                {
                    dist[parent[curr->val]->val] = dist[curr->val] + 1;
                    q.push(parent[curr->val]);
                }
            }
        }
        return result;
    }
};