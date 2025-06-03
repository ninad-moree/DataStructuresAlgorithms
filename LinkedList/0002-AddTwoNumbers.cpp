/*
    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, 
    and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
    Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        ListNode* ansHead = new ListNode();
        ListNode* ans = ansHead;

        int carry = 0;

        while(t1 != NULL && t2 != NULL) {
            int n1 = t1->val;
            int n2 = t2->val;

            int sum = n1 + n2 + carry;

            int digit = sum%10;
            carry = sum/10;

            ListNode* node = new ListNode(digit);
            ans->next = node;
            ans = ans->next;

            t1 = t1->next;
            t2 = t2->next;
        }

        while(t1 != NULL) {
            int n1 = t1->val;
            
            int sum = n1 + carry;

            int digit = sum%10;
            carry = sum/10;

            ListNode* node = new ListNode(digit);
            ans->next = node;
            ans = ans->next;

            t1 = t1->next;
        }

        while(t2 != NULL) {
            int n1 = t2->val;
            
            int sum = n1 + carry;

            int digit = sum%10;
            carry = sum/10;

            ListNode* node = new ListNode(digit);
            ans->next = node;
            ans = ans->next;

            t2 = t2->next;
        }

        if(carry != 0) {
            ListNode* node = new ListNode(carry);
            ans->next = node;
        }

        return ansHead->next;
    }
};