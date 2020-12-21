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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        vector<TreeNode *> list;
        list.push_back(root);
        int pop = 1;
        int width = 1;
        bool t = false;

        while (!list.empty())
        {
            if (pop == 0)
            {
                if (!t)
                {
                    return width;
                }
                t = false;
                pop = list.size();
                int start = 0;
                while (start < pop && list[start] == NULL)
                {
                    start++;
                }
                int end = pop - 1;
                while (end >= 0 && list[end] == NULL)
                {
                    end--;
                }
                if (start == pop && end == -1)
                {
                    break;
                }
                width = max(width, end - start + 1);
            }
            TreeNode *curr = list[0];
            list.erase(list.begin());
            if (curr != NULL)
            {
                list.push_back(curr->left);
                list.push_back(curr->right);
                if (!t)
                {
                    if (curr->left || curr->right)
                    {
                        t = true;
                    }
                }
            }
            else
            {
                list.push_back(NULL);
                list.push_back(NULL);
            }
            pop--;
        }
        return width;
    }
};

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if (root == NULL)
        {
            return 0;
        }

        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        int width = 0;

        while (!q.empty())
        {
            int size = q.size();
            auto first = q.front();
            pair<TreeNode *, int> curr = {};

            while (size-- > 0)
            {
                curr = q.front();
                q.pop();
                TreeNode *n = curr.first;
                int i = curr.second;
                if (i >= INT_MAX)
                {
                    return width;
                }
                if (n->left)
                {
                    q.push({n->left, 2 * i});
                }
                if (n->right)
                {
                    q.push({n->right, 2 * i + 1});
                }
            }
            width = max(width, curr.second - first.second + 1);
        }
        return width;
    }
};