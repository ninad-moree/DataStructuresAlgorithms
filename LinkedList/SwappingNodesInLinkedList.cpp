/*
    You are given the head of a linked list, and an integer k.
    Return the head of the linked list after swapping the values of the kth node 
    from the beginning and the kth node from the end (the list is 1-indexed).

    Example 1:
    Input: head = [1,2,3,4,5], k = 2
    Output: [1,4,3,2,5]
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
    ListNode* swapNodes(ListNode* head, int& k) {
        int len = 0;

        ListNode* temp1 = head;
        ListNode* temp2 = head;

        while(temp1) {
            len++;
            temp1 = temp1->next;
        }
        temp1 = head;
        
        for(int i=1; i<k; i++)
            temp1 = temp1->next;
        
        for(int i=1; i<len-k+1; i++)
            temp2 = temp2->next;
        
        int v1 = temp1->val;
        int v2 = temp2->val;

        temp1->val = v2;
        temp2->val = v1;
        
        return head;
    }
};