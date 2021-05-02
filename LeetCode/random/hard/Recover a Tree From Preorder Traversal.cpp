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
    TreeNode *recoverFromPreorder(string S)
    {
        int n = S.size();

        string num = "";
        int i = 0;
        while (i < n && S[i] != '-')
        {
            num += S[i];
            i++;
        }
        TreeNode *root = new TreeNode(stoi(num));
        num = "";

        stack<pair<TreeNode *, int>> st;
        st.push({root, 0});

        for (; i < n;)
        {
            int depth = 0;
            while (i < n && S[i] == '-')
            {
                depth++;
                i++;
            }
            while (i < n && S[i] != '-')
            {
                num += S[i];
                i++;
            }

            TreeNode *newNode = new TreeNode(stoi(num));
            num = "";

            while (!st.empty())
            {
                auto it = st.top();
                if (it.second + 1 != depth)
                    st.pop();
                else
                    break;
            }

            TreeNode *parent = st.top().first;
            if (parent->left == NULL)
            {
                parent->left = newNode;
            }
            else
            {
                parent->right = newNode;
            }
            st.push({newNode, depth});
        }

        return root;
    }
};