/*
    Design your implementation of the circular double-ended queue (deque).Implement the MyCircularDeque class:
    MyCircularDeque(int k) Initializes the deque with a maximum size of k.
    boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
    boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
    boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
    boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
    int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
    int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
    boolean isEmpty() Returns true if the deque is empty, or false otherwise.
    boolean isFull() Returns true if the deque is full, or false otherwise.

    Example 1:
    Input
    ["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
    [[3], [1], [2], [3], [4], [], [], [], [4], []]
    Output: [null, true, true, true, false, 2, true, true, true, 4]
    Explanation
    MyCircularDeque myCircularDeque = new MyCircularDeque(3);
    myCircularDeque.insertLast(1);  // return True
    myCircularDeque.insertLast(2);  // return True
    myCircularDeque.insertFront(3); // return True
    myCircularDeque.insertFront(4); // return False, the queue is full.
    myCircularDeque.getRear();      // return 2
    myCircularDeque.isFull();       // return True
    myCircularDeque.deleteLast();   // return True
    myCircularDeque.insertFront(4); // return True
    myCircularDeque.getFront();     // return 4
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class MyCircularDeque {
public:
    Node* queueHead;
    Node* queueTail;
    int size;
    int capacity;
    
    MyCircularDeque(int k) {
        capacity = k;
        size = 0;
        queueHead=NULL;
        queueTail=NULL;
    }
    
    bool insertFront(int value) {
        if(isFull()) 
            return false;

        if(queueHead==NULL){
            queueHead = new Node(value);
            queueTail = queueHead; 
        }else{
            Node* newHead = new Node(value);
            newHead->next = queueHead;
            queueHead->prev = newHead;
            queueHead = newHead;
        }

        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) 
            return false;

        if(queueHead==NULL){
            queueHead = new Node(value);
            queueTail = queueHead;
        }else{
            Node* newNode = new Node(value);
            queueTail->next = newNode;
            newNode->prev = queueTail;
            queueTail = newNode;
        }

        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())
            return false;

        if(size==1) {
            queueHead=NULL;
            queueTail=NULL;
            size=0;
            return true;
        }

        queueHead = queueHead->next;
        size--;

        return true;

    }
    
    bool deleteLast() {
        if(isEmpty()) 
            return false;

        if(size==1) {
            queueHead=NULL;
            queueTail=NULL;
            size=0;
            return true;
        }

        queueTail = queueTail->prev;
        size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty())
            return -1;
        return queueHead->data;
    }
    
    int getRear() {
        if(isEmpty()) 
            return -1;
        return queueTail->data;
    }
    
    bool isEmpty() {
        if(size==0) 
            return true;
        return false;
    }
    
    bool isFull() {
        if(size==capacity) 
            return true; 
        return false;
    }
};