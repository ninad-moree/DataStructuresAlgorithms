/*
    You are given a linked list containing 'n' 'head' nodes, where every node in the linked list contains two pointers:
    (1) ‘next’ which points to the next node in the list

    (2) ‘child’ pointer to a linked list where the current node is the head.

    Each of these child linked lists is in sorted order and connected by 'child' pointer.
    Your task is to flatten this linked such that all nodes appear in a single layer or level in a 'sorted order'.
*/
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
	int data;
	Node *next;
 	Node *child;
	Node() : data(0), next(nullptr), child(nullptr){};
	Node(int x) : data(x), next(nullptr), child(nullptr) {}
	Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

Node* mergeLists(Node* a, Node* b) {
    if (!a) 
        return b;
    if (!b) 
        return a;

    Node* result;

    if (a->data < b->data) {
        result = a;
        result->next = mergeLists(a->next, b);
    } else {
        result = b;
        result->next = mergeLists(a, b->next);
    }

    return result;
}

Node* flattenLinkedList(Node* head) {
    if (!head) return nullptr;

    Node* current = head;

    while (current) {
        if (current->child) {
            Node* nextNode = current->next;
            current->next = flattenLinkedList(current->child);
            current->child = nullptr;

            Node* temp = current->next;
            while (temp && temp->next)
                temp = temp->next;

            temp->next = nextNode;
            
        }
        current = current->next;
    }

    return head;
}
