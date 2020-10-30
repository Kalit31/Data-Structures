#include <bits/stdc++.h>
using namespace std;

//Type: Trees
//Approach: Apply an inorder traversal on the tree.
//          If the value of the current node matches, return it.
//Complexity: O(NUM_NODES) time

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
    TreeNode *searchBST(TreeNode *root, int val)
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
            if (curr->val == val)
            {
                return curr;
            }
            curr = curr->right;
        }
        return NULL;
    }
};