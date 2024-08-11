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
        if (!head) 
            return NULL;

        while (head && head->val == val) 
            head = head->next;

        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp) {
            if (temp->val == val) {
                if (prev) 
                    prev->next = temp->next;
                temp = temp->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};