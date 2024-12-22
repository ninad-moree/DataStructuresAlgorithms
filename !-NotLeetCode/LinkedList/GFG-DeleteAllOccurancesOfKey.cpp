/*
    You’re given a linked list and a key 'k'. Delete all the nodes having data equal to ‘k’.

    Sample Input 1:
    10 4 10 3 5 20 10
    10
    Sample Output 1:
    4 3 5 20
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    Node (int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};

Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here
    while (head != nullptr && head->data == k) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* curr = head;
    Node* prev = nullptr;
    while (curr) {
        if (curr->data == k) {
            if (prev != nullptr)
                prev->next = curr->next;
            
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}