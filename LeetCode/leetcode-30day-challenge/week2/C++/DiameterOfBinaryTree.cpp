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

//Type: Trees

//Approach: Mainter an answer variable. Start traversing the tree recursively.
//          At each node, find out the depth in the left and right node.
//          Update the answer if (left depth + right depth + 1(current node)) is greater than ans.

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = 1;
        build(root, ans);
        return ans - 1;
    }

    int build(TreeNode *n, int &ans)
    {
        if (n == NULL)
        {
            return 0;
        }
        int left = build(n->left, ans);
        int right = build(n->right, ans);
        ans = max(ans, left + right + 1);
        return 1 + max(left, right);
    }
};