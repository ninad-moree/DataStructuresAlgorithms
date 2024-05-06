/*
    You are given the head of a linked list.
    Remove every node which has a node with a greater value anywhere to the right side of it.
    Return the head of the modified linked list.

    Example 1:
    Input: head = [5,2,13,3,8]
    Output: [13,8]
    Explanation: The nodes that should be removed are 5, 2 and 3.
    - Node 13 is to the right of node 5.
    - Node 13 is to the right of node 2.
    - Node 8 is to the right of node 3.
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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;

        ListNode* temp = head;

        while(temp) {
            while(!st.empty() && st.top()->val < temp->val)
                st.pop();
            
            st.push(temp);
            temp = temp->next;
        }

        ListNode* curr = nullptr;

        while(!st.empty()) {
            temp = st.top();
            st.pop();
            temp->next = curr;
            curr = temp;
        }

        return temp;
    }
};