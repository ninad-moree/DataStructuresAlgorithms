/*
    You are given the head of a linked list, which contains a series of integers separated by 0's. 
    The beginning and end of the linked list will have Node.val == 0.
    For every two consecutive 0's, merge all the nodes lying in between them into a single node whose 
    value is the sum of all the merged nodes. The modified list should not contain any 0's.
    Return the head of the modified linked list.

    Example 1:
    Input: head = [0,3,1,0,4,5,2,0]
    Output: [4,11]
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ansHead = new ListNode(0);
        ListNode* ans = ansHead;

        int sum=0;
        head = head->next;

        while(head) {
            sum = sum + head->val;
            if(head->val == 0) {
                ListNode* temp = new ListNode(sum);
                ans->next = temp;
                ans = ans->next;
                sum=0;
            }
            head = head->next;
        }
        
        return ansHead->next;
    }
};