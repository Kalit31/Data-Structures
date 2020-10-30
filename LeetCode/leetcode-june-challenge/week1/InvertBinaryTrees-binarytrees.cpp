#include <bits/stdc++.h>
using namespace std;

//Type: Trees
//Approach: We perform an inorder traversal of the tree.
//          At every node we flip it's children.
//          Care must be taken in the traversal part. Instead of curr = curr->right, we apply curr = curr->left
//Complexity: O(N) time and O(N) space

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
    TreeNode *invertTree(TreeNode *root)
    {
        stack<TreeNode *> st;
        TreeNode *curr = root;

        while (curr != NULL || !st.empty())
        {
            while (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            TreeNode *leftChild = curr->left;
            TreeNode *rightChild = curr->right;
            curr->left = rightChild;
            curr->right = leftChild;

            curr = curr->left;
        }

        return root;
    }
};