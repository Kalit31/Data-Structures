#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
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
    TreeNode *result = NULL;
    int depth = 0;

    int build(TreeNode *curr, int d)
    {
        if (!curr)
        {
            return d - 1;
        }
        if (result == NULL)
        {
            if (d == depth)
            {
                result = curr;
            }
        }
        int left = build(curr->left, d + 1);
        int right = build(curr->right, d + 1);
        if (left == depth && right == depth)
        {
            result = curr;
        }
        return max(left, right);
    }

    void findDeepest(TreeNode *curr, int d)
    {
        if (curr == NULL)
        {
            return;
        }
        depth = max(depth, d);
        findDeepest(curr->left, d + 1);
        findDeepest(curr->right, d + 1);
    }

    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        depth = 0;
        findDeepest(root, 0);
        result = NULL;
        build(root, 0);
        return result;
    }
};