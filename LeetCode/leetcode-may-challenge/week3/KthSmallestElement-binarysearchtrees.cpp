#include <bits/stdc++.h>
using namespace std;

//Type: Trees
//Approach: InOrder Traversal
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
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> st;
        TreeNode *curr = root;
        int i = 0;

        while (curr != NULL || !st.empty())
        {
            while (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            i++;
            if (i == k)
            {
                return curr->val;
            }
            curr = curr->right;
        }
        return 0;
    }
};