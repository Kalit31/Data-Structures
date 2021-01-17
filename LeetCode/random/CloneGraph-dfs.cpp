#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
        {
            return NULL;
        }

        vector<Node *> visited(1000, NULL);

        Node *copy = new Node(node->val);
        visited[node->val] = copy;

        dfs(node, copy, visited);

        return copy;
    }

    void dfs(Node *curr, Node *node, vector<Node *> &visited)
    {
        visited[curr->val] = node;
        for (auto n : curr->neighbors)
        {
            if (visited[n->val] == NULL)
            {
                Node *newNode = new Node(n->val);
                (node->neighbors).push_back(newNode);
                dfs(n, newNode, visited);
            }
            else
            {
                (node->neighbors).push_back(visited[n->val]);
            }
        }
    }
};