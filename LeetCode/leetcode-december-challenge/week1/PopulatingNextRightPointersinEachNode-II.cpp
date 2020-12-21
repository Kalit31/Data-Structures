#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
        {
            return root;
        }
        queue<Node *> q;
        q.push(root);
        int genPop = 1;
        vector<Node *> currLevel;

        while (!q.empty())
        {
            if (genPop == 0)
            {
                for (int i = 0; i < currLevel.size(); i++)
                {
                    if (i == currLevel.size() - 1)
                    {
                        currLevel[i]->next = NULL;
                    }
                    else
                    {
                        currLevel[i]->next = currLevel[i + 1];
                    }
                }
                currLevel.clear();
                genPop = q.size();
            }
            Node *curr = q.front();
            q.pop();
            currLevel.push_back(curr);

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
            genPop--;
        }
        for (int i = 0; i < currLevel.size(); i++)
        {
            if (i == currLevel.size() - 1)
            {
                currLevel[i]->next = NULL;
            }
            else
            {
                currLevel[i]->next = currLevel[i + 1];
            }
        }
        return root;
    }
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int levelSize = q.size();
            int size = levelSize;
            int count = 0;
            for (int i = 0; i < levelSize; i++)
            {
                Node *temp = q.front();
                q.pop();
                if (count + 1 == size)
                    temp->next = NULL;
                else
                    temp->next = q.front();
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
                count++;
            }
        }
        return root;
    }
};
