#include <bits/stdc++.h>
using namespace std;

//Type: Implementation, Linked List, Maps
//Approach: We shall maintain a linked list of nodes,
//          and keep adding elements at the head of list
//          Now, to have access of the elements in O(1) time,
//          we will have to use a map data structure,
//          which will store the ptr to the node corresponding to the key.
//          The back of the linkedlist will contain the least recently used nodes.
//Complexity: O(1) time

class LRUCache
{
public:
    struct Node
    {
        int key;
        int value;
        Node *next;
        Node *prev;
        Node() : next(nullptr), prev(nullptr) {}
        Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    };

    Node *head = new Node;
    Node *tail = new Node;
    unordered_map<int, Node *> nodeMap;
    int cap;

    void addNode(Node *node)
    {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    void removeNode(Node *node)
    {
        Node *next = node->next;
        Node *prev = node->prev;
        next->prev = prev;
        prev->next = next;
    }

    LRUCache(int capacity)
    {
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }

    int get(int key)
    {
        int result = -1;
        if (nodeMap.count(key))
        {
            removeNode(nodeMap[key]);
            addNode(nodeMap[key]);
            result = nodeMap[key]->value;
        }
        return result;
    }

    void put(int key, int value)
    {
        if (nodeMap.count(key))
        {
            removeNode(nodeMap[key]);
            nodeMap[key]->value = value;
            addNode(nodeMap[key]);
        }
        else
        {
            if (nodeMap.size() == cap)
            {
                Node *toRemove = tail->prev;
                nodeMap.erase(toRemove->key);
                removeNode(toRemove);
            }
            Node *newNode = new Node{key, value};
            nodeMap[key] = newNode;
            addNode(newNode);
        }
    }
};