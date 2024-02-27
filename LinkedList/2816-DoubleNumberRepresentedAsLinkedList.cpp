/*
    You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.
    Return the head of the linked list after doubling it.

    Example 1:
    Input: head = [1,8,9]
    Output: [3,7,8]
    Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the 
    returned linked list represents the number 189 * 2 = 378.
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
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while(curr!=nullptr) {
            ListNode * next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* doubleIt(ListNode* head) {
        head = reverseLinkedList(head);
        ListNode* temp = head;
        int c = 0;
        int val = 0;

        while (temp) {
            val = temp->val * 2 + c;
            c = val / 10; 
            temp->val = val % 10; 
            temp = temp->next;
        }

        if (c > 0) {
            ListNode* newnode = new ListNode(c);
            newnode->next = nullptr;

            ListNode* last = head;
            while (last->next) {
                last = last->next;
            }

            last->next = newnode;
        }
        head = reverseLinkedList(head);
        return head;

    }
};