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
        if (head == nullptr || head->next == nullptr) {
            // Base case: Empty list or list with only one node
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Swap the nodes
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // Move to the next pair of nodes
            prev = first;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
