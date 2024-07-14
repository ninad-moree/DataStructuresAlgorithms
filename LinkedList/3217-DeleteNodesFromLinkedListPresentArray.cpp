/*
    You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all 
    nodes from the linked list that have a value that exists in nums.
    
    Example 1:
    Input: nums = [1,2,3], head = [1,2,3,4,5]
    Output: [4,5]
    Explanation:
    Remove the nodes with values 1, 2, and 3.
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        set<int> s(nums.begin(), nums.end());

        while(curr != nullptr) {
            if(s.find(curr->val) != s.end()) {
                if(curr == head) {
                    head = curr->next;
                    curr = head;
                } else {
                    prev->next = curr->next;
                    curr = curr->next;
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};