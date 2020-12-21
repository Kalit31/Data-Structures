#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void findPath(TreeNode* n, int currSum, int req, int& count, unordered_map<int, int>& m) {
        if (n == NULL) {
            return;
        }
        currSum += n->val;
        if (m.find(currSum-req) != m.end()) {
            count += m[currSum-req];
        }
        m[currSum]++;
        findPath(n->left, currSum, req, count, m);
        findPath(n->right, currSum, req, count, m);
        m[currSum]--;
        return;
    }



    int pathSum(TreeNode* root, int sum) {
        if (root==NULL) {
            return 0;
        }
        unordered_map<int, int> m;
        m[0] = 1;
        int count = 0;
        findPath(root, 0, sum, count, m);
        return count;
    }
};