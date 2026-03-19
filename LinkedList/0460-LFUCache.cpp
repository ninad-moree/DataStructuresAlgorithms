/*
    Design and implement a data structure for a Least Frequently Used (LFU) cache. Implement the LFUCache class:
    LFUCache(int capacity) Initializes the object with the capacity of the data structure.
    int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
    void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate 
    and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least 
    recently used key would be invalidated.
    To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.
    When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or 
    put operation is called on it. The functions get and put must each run in O(1) average time complexity.

    Example 1:
    Input:
    ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
    [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
    Output: [null, null, null, 1, null, -1, 3, null, -1, 3, 4]
    Explanation:
    // cnt(x) = the use counter for key x
    // cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
    LFUCache lfu = new LFUCache(2);
    lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
    lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    lfu.get(1);      // return 1, // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2., // cache=[3,1], cnt(3)=1, cnt(1)=2
    lfu.get(2);      // return -1 (not found)
    lfu.get(3);      // return 3, // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1., // cache=[4,3], cnt(4)=1, cnt(3)=2
    lfu.get(1);      // return -1 (not found)
    lfu.get(3);      // return 3, // cache=[3,4], cnt(4)=1, cnt(3)=3
    lfu.get(4);      // return 4, // cache=[4,3], cnt(4)=2, cnt(3)=3
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    int val;
    int cnt;
    Node* next;
    Node* prev;

    Node(int k, int v) {
        val = v;
        key = k;
        cnt = 1;
        next = NULL;
        prev = NULL;
    }
};

class List{
public:
    int size;
    Node* head;
    Node* tail;

    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        size--;
    }

    void insertAtHead(Node* node) {
        Node* headNext = head->next;

        head->next = node;
        node->next = headNext;
        node->prev = head;
        headNext->prev = node; 

        size++;
    }
};

class LFUCache {
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int maxSize;
    int minFreq;
    int curSize;
public:
    LFUCache(int capacity) {
        maxSize = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqListMap(Node* node) {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->deleteNode(node);

        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
            minFreq++;

        List* nextHighFreq = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end())
            nextHighFreq = freqListMap[node->cnt + 1];

        node->cnt ++;
        nextHighFreq->insertAtHead(node);
        freqListMap[node->cnt] = nextHighFreq;
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key) == keyNode.end())
            return -1;

        Node* node = keyNode[key];
        int val = node->val;
        updateFreqListMap(node);
        return val;
    }
    
    void put(int key, int value) {
        if(maxSize == 0)
            return;

        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->val = value;
            updateFreqListMap(node);
        } else {
            if(curSize == maxSize) {
                List* list = freqListMap[minFreq];
                Node* lruNode = list->tail->prev;
                keyNode.erase(lruNode->key);
                freqListMap[minFreq]->deleteNode(lruNode);
                curSize--;
            }

            curSize++;

            minFreq = 1;
            List* listFreq = new List();

            if(freqListMap.find(minFreq) != freqListMap.end())
                listFreq = freqListMap[minFreq];

            Node* node = new Node(key, value);
            listFreq->insertAtHead(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};