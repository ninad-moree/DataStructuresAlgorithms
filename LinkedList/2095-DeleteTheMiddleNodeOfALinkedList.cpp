/*
    You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list. The middle node of a linked list of size n is the ⌊n / 2⌋th node
    from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x. For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2.
    
    Example 1:
    Input: head = [1,3,4,7,1,2,6]
    Output: [1,3,4,1,2,6]
    Explanation: The above figure represents the given linked list. The indices of the nodes are written below.Since n = 7, node 3 with value 7 is the middle node, which is marked 
    in red. We return the new list after removing this node. 
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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) 
            return nullptr;

        ListNode* curr = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            curr = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        curr->next = slow->next;

        return head;
    }
};