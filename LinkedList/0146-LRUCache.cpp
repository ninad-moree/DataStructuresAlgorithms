/*
    Design a data structure that follows the constraints of a Least Recently Used (LRU) cache. Implement the LRUCache class:
    LRUCache(int capacity) Initialize the LRU cache with positive size capacity. int get(int key) Return the value of the key if the key exists, 
    otherwise return -1. void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache.
    If the number of keys exceeds the capacity from this operation, evict the least recently used key. The functions get and put must each run in 
    O(1) average time complexity.

    Example 1:
    Input
    ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
    [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
    Output: [null, null, null, 1, null, -1, null, -1, 3, 4]

    Explanation
    LRUCache lRUCache = new LRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    lRUCache.get(1);    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache.get(2);    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache.get(1);    // return -1 (not found)
    lRUCache.get(3);    // return 3
    lRUCache.get(4);    // return 4
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k, int v) {
        val = v;
        key = k;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    int size;

    LRUCache(int capacity) {
        size = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        
        Node* node = mp[key];
        deleteNode(node);
        insertAtHead(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            deleteNode(node);
            insertAtHead(node);
        } else {
            if(mp.size() == size) {
                Node* lruNode = tail->prev;
                mp.erase(lruNode->key);
                deleteNode(lruNode);
            }

            Node* node = new Node(key, value);
            mp[key] = node;
            insertAtHead(node);
        }
        
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAtHead(Node* node) {
        Node* headNext = head->next;

        head->next = node;
        node->next = headNext;
        node->prev = head;
        headNext->prev = node; 
    }
};