/*
    Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
    There is a cycle in a linked list if there is some node in the list that can be reached again by continuously 
    following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is 
    connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
    Do not modify the linked list.

    Input: head = [3,2,0,-4], pos = 1
    Output: tail connects to node index 1
    Explanation: There is a cycle in the linked list, where tail connects to the second node
    3 --> 2--> 0 --> -4 and -4 connects to 2
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow)
                break;
        }

        if(fast == NULL || fast->next == NULL) 
            return NULL;

        while(head != slow) {
            slow = slow->next;
            head = head->next;
        }

        return head;
    }
};