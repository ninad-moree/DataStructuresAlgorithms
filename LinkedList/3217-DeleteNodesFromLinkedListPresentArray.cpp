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
        if(!head)
            return head;
            
        unordered_map<int, int> mp;
        for(auto i : nums)
            mp[i]++;

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp) {
            if(mp.find(temp->val) != mp.end()) {
                ListNode* deleteNode = temp;
                if(deleteNode == head) {
                    head = head->next;
                    temp = head;
                } else {
                    prev->next = temp->next;
                    temp = prev->next;
                }
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};
