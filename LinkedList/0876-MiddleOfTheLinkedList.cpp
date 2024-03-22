/*
    Given the head of a singly linked list, return the middle node of the linked list.
    If there are two middle nodes, return the second middle node.

    Example 1:
    Input: head = [1,2,3,4,5]
    Output: [3,4,5]
    Explanation: The middle node of the list is node 3.
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL ||  head->next==NULL) 
            return head;

        ListNode * fast = head->next;
        ListNode * slow = head;

        while(fast!=NULL) {
            fast = fast->next;
            if(fast!=NULL) 
                fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};