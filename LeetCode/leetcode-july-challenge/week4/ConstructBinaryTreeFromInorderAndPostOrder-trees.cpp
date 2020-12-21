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
    TreeNode *get(vector<int> in, vector<int> post)
    {
        TreeNode *root = NULL;
        if (in.empty())
        {
            return root;
        }
        if (in.size() == 1)
        {
            root = new TreeNode(in[0]);
            root->left = NULL;
            root->right = NULL;
            return root;
        }
        int n = post.size();
        root = new TreeNode(post[n - 1]);
        int ind = find(in.begin(), in.end(), post[n - 1]) - in.begin();
        vector<int> leftIn(in.begin(), in.begin() + ind);
        vector<int> rightIn(in.begin() + ind + 1, in.end());
        post.pop_back();
        vector<int> leftPost(post.begin(), post.begin() + ind);
        vector<int> rightPost(post.begin() + ind, post.end());
        root->left = get(leftIn, leftPost);
        root->right = get(rightIn, rightPost);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0 || inorder.size() != postorder.size())
        {
            return NULL;
        }
        return get(inorder, postorder);
    }
};