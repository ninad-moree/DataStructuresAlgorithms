/*
    Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

    Example 1:
    Input: head = [1,1,2]
    Output: [1,2]
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
            
        ListNode* temp = head;
        ListNode* next = head->next;

        while(next != NULL) {
            if(temp->val == next->val) {
                temp->next = next->next;
                next = temp->next;
            } else {
                temp = temp->next;
                next = temp->next;
            }
        }

        return head;
    }
};