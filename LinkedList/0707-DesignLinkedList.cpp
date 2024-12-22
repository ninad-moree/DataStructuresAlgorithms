/*
    Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
    A node in a singly linked list should have two attributes: val and next. val is the value of the current node, 
    and next is a pointer/reference to the next node.
    If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node 
    in the linked list. Assume all nodes in the linked list are 0-indexed.

    Implement the MyLinkedList class:
    MyLinkedList() Initializes the MyLinkedList object.
    int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
    void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, 
    the new node will be the first node of the linked list.
    void addAtTail(int val) Append a node of value val as the last element of the linked list.
    void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index 
    equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater 
    than the length, the node will not be inserted.
    void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
*/

#include<bits/stdc++.h>
using namespace std;

class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node(int val) : val(val), next(nullptr) {}
    };

    Node* head;
    int size;
    
public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size || !head) {
            return -1;
        }
        
        Node* curr = head;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        
        return curr->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        
        if (!head) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }
        
        if (index == 0) {
            addAtHead(val);
        } else if (index == size) {
            addAtTail(val);
        } else {
            Node* newNode = new Node(val);
            Node* curr = head;
            for (int i = 0; i < index - 1; ++i) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size || !head) {
            return;
        }
        
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* curr = head;
            for (int i = 0; i < index - 1; ++i) {
                curr = curr->next;
            }
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        
        size--;
    }
};