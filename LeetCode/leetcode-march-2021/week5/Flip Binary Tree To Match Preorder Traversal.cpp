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
    vector<int> result;
    int n;
    int ind = 0;
    bool traverse(TreeNode *root, vector<int> &voyage)
    {
        if (root == NULL)
        {
            return true;
        }
        if (ind >= n || root->val != voyage[ind])
        {
            return false;
        }
        ind++;
        if (ind < n && root->left != NULL && root->left->val != voyage[ind])
        {
            //flip
            result.push_back(root->val);
            if (traverse(root->right, voyage))
            {
                return traverse(root->left, voyage);
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (traverse(root->left, voyage))
            {
                return traverse(root->right, voyage);
            }
            else
            {
                return false;
            }
        }
    }

    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage)
    {
        n = voyage.size();
        ind = 0;
        if (!traverse(root, voyage))
        {
            result.clear();
            result.push_back(-1);
        }
        return result;
    }
};