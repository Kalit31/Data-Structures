#include <bits/stdc++.h>
using namespace std;

//Type: Trees
//Approach: We shall apply a BFS and traverse level by level(generation)
//          For each generation, check that the 2 values we want are present.
//          If yes, check if they belong to the same parent.
//Complexity: O(N) time and O(N) space

/**
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
    bool isCousins(TreeNode *root, int x, int y)
    {
        vector<TreeNode *> list;
        vector<int> cousins;
        vector<int> nodes;
        nodes.push_back(root->val);
        cousins.push_back(root->val);
        list.push_back(root);
        int genPop = 1;

        while (!list.empty())
        {
            // Start a new generation(level)
            if (genPop == 0)
            {
                // initalize nodes in level
                genPop = list.size();
                // check if x and y are in the same level
                if (find(cousins.begin(), cousins.end(), x) != cousins.end() && find(cousins.begin(), cousins.end(), y) != cousins.end())
                {
                    // parent of node = (node's index -1)/2
                    int xParent = ((find(nodes.begin(), nodes.end(), x) - nodes.begin()) - 1) / 2;
                    int yParent = ((find(nodes.begin(), nodes.end(), y) - nodes.begin()) - 1) / 2;
                    // if same parent, they are not cousins, else they are
                    if (xParent == yParent)
                    {
                        return false;
                    }
                    else
                    {
                        return true;
                    }
                }
            }
            // Simple bfs
            TreeNode *n = list.front();
            list.erase(list.begin());
            cousins.erase(cousins.begin());

            if (n->left != NULL)
            {
                list.push_back(n->left);
                cousins.push_back(n->left->val);
                nodes.push_back(n->left->val);
            }
            else
            {
                nodes.push_back(-1);
            }

            if (n->right != NULL)
            {
                list.push_back(n->right);
                cousins.push_back(n->right->val);
                nodes.push_back(n->right->val);
            }
            else
            {
                nodes.push_back(-1);
            }
            genPop--;
        }
        return false;
    }
};