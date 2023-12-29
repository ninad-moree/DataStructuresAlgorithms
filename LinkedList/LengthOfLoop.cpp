/*
    You’re given a linked list. The last node might point to null, or it might point to a node 
    in the list, thus forming a cycle.
    Find out whether the linked list has a cycle or not, and the length of the cycle if it does.
    If there is no cycle, return 0, otherwise return the length of the cycle.
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

int lengthOfLoop(Node *head) {
    Node *fast = head;
    Node *slow = head;
    int len;

    while(fast!=NULL && fast->next!=NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow) {
            len=1;
            slow = slow->next;
            while(slow!=fast) {
                slow = slow->next;
                len++;
            }
            return len;
        }
    }
    return 0;
}