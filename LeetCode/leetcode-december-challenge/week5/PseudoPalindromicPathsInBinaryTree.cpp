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
    int count = 0;

    void build(TreeNode *curr, vector<int> &freq)
    {
        if (curr == NULL)
        {
            return;
        }
        freq[curr->val - 1]++;
        if (curr->left == NULL && curr->right == NULL)
        {
            int odd = 0;
            for (int i = 0; i < 9; i++)
            {
                if (freq[i] != 0 && freq[i] % 2 != 0)
                {
                    odd++;
                }
            }
            if (odd <= 1)
            {
                count++;
            }
        }
        if (curr->left != NULL)
        {
            build(curr->left, freq);
        }
        if (curr->right != NULL)
        {
            build(curr->right, freq);
        }
        freq[curr->val - 1]--;
    }

    int pseudoPalindromicPaths(TreeNode *root)
    {
        vector<int> freq(9, 0);
        build(root, freq);
        return count;
    }
};