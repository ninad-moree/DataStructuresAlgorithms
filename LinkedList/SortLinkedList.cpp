/*
    Given the head of a linked list, return the list after sorting it in ascending order.

    Example 1:
    Input: head = [4,2,1,3]
    Output: [1,2,3,4]
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
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        if(left == NULL) return right;
        if(right == NULL) return left;

        ListNode* ansHead = new ListNode(-1);
        ListNode* ansTail = ansHead;
        while(left != NULL && right != NULL) {
            if(left->val < right->val) {
                ansTail->next = left;
                ansTail = left;
                left = left->next;
            } 
            else {
                ansTail->next = right;
                ansTail = right;
                right = right->next;
            }
        }
        while(left != NULL) {
            ansTail->next = left;
            ansTail = left;
            left = left->next;
        }
        while(right != NULL) {
            ansTail->next = right;
            ansTail = right;
            right = right->next;
        }
        return ansHead->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        ListNode* result = merge(left, right);
        return result;
    }
};