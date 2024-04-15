/*
    You're given a positive integer represented in the form of a singly linked-list of digits. The length of the number is 'n'.
    Add 1 to the number, i.e., increment the given number by one.
    The digits are stored such that the most significant digit is at the head of the linked list and the least significant digit is at 
    the tail of the linked list.

    Example:
    Input: Initial Linked List: 1 -> 5 -> 2
    Output: Modified Linked List: 1 -> 5 -> 3
    Explanation: Initially the number is 152. After incrementing it by 1, the number becomes 153.
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

Node* reverseLinkedList(Node* head) {
    Node* prev = NULL;
    Node* temp = head;

    while(temp != NULL) {
        Node* next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    return prev;
}

Node *addOne(Node *head)
{
    // Write Your Code Here.
    head = reverseLinkedList(head);

    int carry = 1;

    Node* temp = head;
    Node* prev = nullptr; 

    while(temp != NULL && carry != 0) {
        int sum = temp->data + carry;
        carry = sum / 10;

        temp->data = sum%10;
        prev = temp;
        temp = temp->next;
    }    

    while(carry != 0) {
         Node* newNode = new Node(carry);
        if (prev != NULL) {
          prev->next = newNode;
        } else
          head = newNode;
        carry = carry/10;
    }

    head = reverseLinkedList(head);

    return head;
}