/*
    Given the head of a linked list and an integer val, remove all the nodes of the 
    linked list that has Node.val == val, and return the new head.
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;

        ListNode *temp = new ListNode(0);
        ListNode *curr = temp;
        temp->next = head;

        while(temp!=NULL && temp->next!=NULL) {
            if(temp->next->val == val)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        return curr->next;
    }
};