/*
    Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. You need to sort the linked list 
    in non-decreasing order and the return the head of the sorted list.

    Example:
    Given linked list is 1 -> 0 -> 2 -> 1 -> 2. 
    The sorted list for the given linked list will be 0 -> 1 -> 1 -> 2 -> 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


Node* sortList(Node *head) {
    // Write your code here.
    Node* zeroHead = new Node(0);
    Node* oneHead = new Node(0);
    Node* twoHead = new Node(0);

    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;

    while(head != NULL) {
        if(head->data == 0) {
            zero->next = head;
            zero = zero->next;
            head = head->next;
        } else if(head->data == 1) {
            one->next = head;
            one = one->next;
            head = head->next;
        } else {
            two->next = head;
            two = two->next;
            head = head->next;
        }
    }

    one->next = twoHead->next;
    two->next = NULL;
    

    if(oneHead->next == NULL)
        zero->next = twoHead->next;
    else 
        zero->next = oneHead->next;
    
    return zeroHead->next;
}