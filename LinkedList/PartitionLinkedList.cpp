/*
    Given the head of a linked list and a value x, partition it such that all nodes less than x come 
    before nodes greater than or equal to x.
    You should preserve the original relative order of the nodes in each of the two partitions.

    Example 1:
    Input: head = [1,4,3,2,5,2], x = 3
    Output: [1,2,2,4,3,5]
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallerHead = new ListNode(0); 
        ListNode* smaller = smallerHead;
        ListNode* greaterHead = new ListNode(0); 
        ListNode* greater = greaterHead;

        ListNode* current = head;
        while (current != NULL) {
            if (current->val < x) {
                smaller->next = current;
                smaller = smaller->next;
            } 
            else {
                greater->next = current;
                greater = greater->next;
            }
            current = current->next;
        }

        smaller->next = greaterHead->next;
        greater->next = NULL;

        ListNode* result = smallerHead->next;

        delete smallerHead;
        delete greaterHead;

        return result;
    }
};