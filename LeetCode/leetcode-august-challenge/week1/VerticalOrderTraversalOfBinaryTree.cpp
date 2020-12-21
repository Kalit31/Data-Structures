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
    void dfs(map<pair<int, int>, set<int>>& map, TreeNode* root, int x, int y, int& maxValue, int& minValue) {
        if (root==NULL) {
            return;
        }
        map[{x, y}].insert(root->val);
        maxValue = max(maxValue, x);
        minValue = min(minValue, x);
        dfs(map, root->left, x-1, y+1, maxValue, minValue);
        dfs(map, root->right, x+1, y+1, maxValue, minValue);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};
        map <pair<int, int>, set<int>> m;
        int maxValue = INT_MIN;
        int minValue = INT_MAX;
        dfs(m, root, 0, 0, maxValue, minValue);
        vector<vector<int>> result(maxValue-minValue+1);
        for (auto it=m.begin();it!=m.end();it++) {
            int index = (it->first).first - minValue;
            result[index].insert(result[index].end(), (it->second).begin(), (it->second).end());
        }
        return result;
    }
};