#include <bits/stdc++.h>
using namespace std;

// Look in LeetCode 30 day challenge(April)

/*
  Definition for a binary tree node.*/
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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<TreeNode *> nodeStack;
        TreeNode *root = new TreeNode{preorder[0]};
        nodeStack.push(root);
        TreeNode *current = root;
        for (int i = 1; i < preorder.size(); i++)
        {
            TreeNode *temp = new TreeNode{preorder[i]};
            if (temp->val < nodeStack.top()->val)
            {
                current->left = temp;
                nodeStack.push(temp);
                current = temp;
            }
            else
            {
                TreeNode *poppedNode = new TreeNode;
                while (!nodeStack.empty() && nodeStack.top()->val < preorder[i])
                {
                    poppedNode = nodeStack.top();
                    nodeStack.pop();
                }
                poppedNode->right = temp;
                nodeStack.push(temp);
                current = temp;
            }
        }
        return root;
    }
};