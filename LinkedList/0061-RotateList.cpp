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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0)
            return head;

        int len = 1;
        ListNode* temp = head;

        while(temp->next) {
            len++;
            temp = temp->next;
        }

        temp->next = head;
        k = k%len;

        int cnt = len - k;
        temp = head;

        while(cnt > 1) {
            temp = temp->next;
            cnt--;
        }

        head = temp->next;
        temp->next = NULL;

        return head;
    }
};