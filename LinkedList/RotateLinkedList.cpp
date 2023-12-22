/*
    Given the head of a linked list, rotate the list to the right by k places.

    Example 1:
    Input: head = [1,2,3,4,5], k = 2
    Output: [4,5,1,2,3]
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

    int getLength(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        
        int len = getLength(head);

        if(head == NULL || head->next == NULL)
            return head;

        for(int i=1; i<=k%len; i++) {
            while(temp!=NULL && temp->next!=NULL) {
                prev = temp;
                temp = temp->next;
            }
            temp->next = head;
            prev->next = NULL;
            head = temp;
        }
        return temp;
    }
};