/*
    Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts. The length of each part should
    be as equal as possible: no two parts should have a size  differing by more than one. This may lead to some parts being null.  The parts should be 
    in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.
    Return an array of the k parts.

    Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
    Output: [[1,2,3,4],[5,6,7],[8,9,10]]
    Explanation: The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later 
    parts.
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        ListNode* current = head;
        while (current) {
            length++;
            current = current->next;
        }

        int minSize = length / k;
        int largerParts = length % k;

        vector<ListNode*> result;
        current = head;
        for (int i = 0; i < k; i++) {
            int partSize = (i < largerParts) ? (minSize + 1) : minSize;

            if (partSize == 0) {
                result.push_back(nullptr);
                continue;
            }

            result.push_back(current);

            for (int j = 0; j < partSize - 1; j++) 
                current = current->next;

            ListNode* temp = current->next;
            current->next = nullptr;
            current = temp;
        }

        return result;
    }
};
