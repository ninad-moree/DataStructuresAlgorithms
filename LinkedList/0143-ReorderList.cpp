/*
    You are given the head of a singly linked-list. The list can be represented as:
    L0 → L1 → … → Ln - 1 → Ln
    Reorder the list to be on the following form:

    L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
    You may not modify the values in the list's nodes. Only nodes themselves may be changed.

    Input: head = [1,2,3,4]
    Output: [1,4,2,3]
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
    void reorderList(ListNode* head) {
        int s = 0;
        ListNode* temp = head;
        stack<ListNode*> st;
        while(temp!=NULL) {
            st.push(temp);
            s++;
            temp = temp->next;
        }
        temp = head;
        for(int i=0;i<s/2;i++) {
            ListNode* nextNode = temp->next;
            temp->next = st.top();
            st.pop();
            temp = temp->next;
            temp->next = nextNode;
            temp = nextNode;
        }
        temp->next = NULL;
    }
};