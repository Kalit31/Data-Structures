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

class BSTIterator
{
public:
    int totalElements = 0;
    vector<int> inOrder;

    void inorderTraversal(TreeNode *curr)
    {
        if (curr->left)
        {
            inorderTraversal(curr->left);
        }
        inOrder.push_back(curr->val);
        if (curr->right)
        {
            inorderTraversal(curr->right);
        }
    }

    int currInd = 0;

    BSTIterator(TreeNode *root)
    {
        inOrder.clear();
        inorderTraversal(root);
        totalElements = inOrder.size();
        currInd = 0;
    }

    int next()
    {
        return inOrder[currInd++];
    }

    bool hasNext()
    {
        return currInd < totalElements;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */