/*
    Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem 
    without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

    Input: head = [1,2,3,4]
    Output: [2,1,4,3]
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        if(head->next->next == NULL) {
            int v = head->val;
            head->val = head->next->val;
            head->next->val = v;
            return head;
        }

        ListNode* prev = head;
        ListNode* temp = head->next;

        while(prev && temp) {
            int val = prev->val;
            prev->val = temp->val;
            temp->val = val;

            if(temp == NULL || temp->next == NULL )
                break;

            prev = temp->next;
            temp = temp->next->next;
        }

        return head;
    }
};
