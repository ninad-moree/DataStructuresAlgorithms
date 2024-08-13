/*
    Given the head of a singly linked list and two integers left and right where left <= right, 
    reverse the nodes of the list from position left to position right, and return the reversed list.

    Example 1:
    Input: head = [1,2,3,4,5], left = 2, right = 4
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) 
            return head;

        ListNode *temp = head;
        ListNode *ansHead = head;
        stack<int> s;

        int l=1;
        while(l<left) {
            head = head->next;
            l++;
        }

        int beg = l;
        while(l<=right) {
            s.push(head->val);
            head = head->next;
            l++;
        }

        int cnt = 1;
        while(cnt<beg) {
            temp = temp->next;
            cnt++;
        }

        while(!s.empty()) {
            int ele = s.top();
            s.pop();
            temp->val = ele;
            temp = temp->next;
        }

        return ansHead;
    }
};