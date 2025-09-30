/*
    Given the head of a linked list, return the list after sorting it in ascending order.

    Example 1:
    Input: head = [4,2,1,3]
    Output: [1,2,3,4]
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
    struct Cmp {
        bool operator()(pair<int, ListNode*>& p1, pair<int, ListNode*>& p2) {
            return p1.first > p2.first;
        }
    };

    ListNode* sortList(ListNode* head) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, Cmp> pq;

        ListNode* curr = head;
        while(curr != NULL) {
            pq.push({curr->val, curr});
            curr = curr->next;
        }

        ListNode* ans = new ListNode(0, NULL);
        ListNode* ansHead = ans;
        while(!pq.empty()) {
            ans->next = pq.top().second;
            ans = ans->next;
            pq.pop();
        }
        ans->next = NULL;

        return ansHead->next;
    }
};