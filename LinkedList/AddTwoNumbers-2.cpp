/*
    You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes 
    first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Input: l1 = [7,2,4,3], l2 = [5,6,4]
    Output: [7,8,0,7]
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* reversed1 = reverseList(l1);
        ListNode* reversed2 = reverseList(l2);

        ListNode* dummy = new ListNode(0); 
        ListNode* current = dummy;
        int carry = 0;

        while (reversed1 != nullptr || reversed2 != nullptr || carry != 0) {
            int sum = carry;
            if (reversed1 != nullptr) {
                sum += reversed1->val;
                reversed1 = reversed1->next;
            }
            if (reversed2 != nullptr) {
                sum += reversed2->val;
                reversed2 = reversed2->next;
            }

            carry = sum / 10;
            int digit = sum % 10;

            ListNode* newNode = new ListNode(digit);
            current->next = newNode;
            current = current->next;
        }

        ListNode* result = reverseList(dummy->next);
        delete dummy; 
        return result;
    }
};