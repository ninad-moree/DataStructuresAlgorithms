/*
    Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that 
    sum to 0 until there are no such sequences.
    After doing so, return the head of the final linked list.  You may return any such answer.

    Example 1:
    Input: head = [1,2,-3,3,1]
    Output: [3,1]
    Note: The answer [1,2,1] would also be accepted.
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> arr;

        ListNode* temp = head;
        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        for (int i = 0; i < arr.size(); i++) {
            int sum = 0;
            for (int j = i; j < arr.size(); j++) {
                sum += arr[j];
                if (sum == 0) {
                    arr.erase(arr.begin() + i, arr.begin() + j + 1);
                    i--;
                    break;
                }
            }
        }

        if (arr.empty()) 
            return nullptr;

        ListNode* newHead = new ListNode(arr[0]);
        temp = newHead;
        for (int i = 1; i < arr.size(); i++) {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }

        return newHead;
    }
};