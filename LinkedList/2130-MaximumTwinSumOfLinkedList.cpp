/*
    In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as 
    the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.
    For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are 
    the only nodes with twins for n = 4.
    The twin sum is defined as the sum of a node and its twin.
    Given the head of a linked list with even length, return the maximum twin sum of the linked list.

    Input: head = [4,2,2,3]
    Output: 7
    Explanation:
    The nodes with twins present in this linked list are:
    - Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
    - Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
    Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 
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
    int pairSum(ListNode* head) {
        stack<ListNode*> st;
        int len = 0;
        ListNode* temp = head;
        while(temp) {
            st.push(temp);
            len++;
            temp = temp->next;
        }
        temp = head;
        int sum = INT_MIN;
        for(int i=0;i<len/2;i++) {
            sum = max(sum, temp->val + st.top()->val);
            temp = temp->next;
            st.pop();
        }
        return sum;
    }
};