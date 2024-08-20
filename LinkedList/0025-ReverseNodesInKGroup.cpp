/*
    Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
    k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes 
    is not a multiple of k then left-out nodes, in the end, should remain as it is.
    You may not alter the values in the list's nodes, only nodes themselves may be changed.

    Example 1:
    Input: head = [1,2,3,4,5], k = 2
    Output: [2,1,4,3,5]
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
    int length(ListNode* head){
        int count=0;
        while(head){
            count++;
            head= head->next;
        }
        return count;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = length(head);
        if(head == NULL) 
            return NULL;

        ListNode *forward = NULL;
        ListNode *curr = head;
        ListNode *prev = NULL;

        int cnt = 0;

        while(curr != NULL && cnt<k) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            cnt++;
        }
        size-=k;

        if(forward!=NULL && size>=k) 
            head->next = reverseKGroup(forward, k);
        else 
            head->next = forward;

        return prev;
    }
};