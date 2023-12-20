/*
    Given the head of a linked list, remove the nth node from the end of the list and return its head.

    Example 1:
    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        int len = 0;

        while (temp != nullptr) {
            temp = temp->next;
            len++;
        }

        int pos = len - n;

        if (pos == 0) {
            temp = head;
            head = head->next;
            delete temp;
        } 
        else {
            temp = head;
            while (pos > 0) {
                prev = temp;
                temp = temp->next;
                pos--;
            }

            prev->next = temp->next;
            delete temp;
        }

        return head;
    }
};