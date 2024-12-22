/*
    You are given two linked lists: list1 and list2 of sizes n and m respectively.
    Remove list1's nodes from the ath node to the bth node, and put list2 in their place.
    The blue edges and nodes in the following figure indicate the result:
    Build the result list and return its head.

    Example 1:
    Input: list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
    Output: [0,1,2,1000000,1000001,1000002,5]
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* anext = list1;
        ListNode* aprev = nullptr;
        int cnta = 0;

        while (cnta != a) {
            aprev = anext;
            anext = anext->next;
            cnta++;
        }

        int cntb = a;
        while (cntb != b + 1) {
            anext = anext->next;
            cntb++;
        }

        if (aprev != nullptr)
            aprev->next = list2;
        else
            list1 = list2;
        
        ListNode* list2tail = list2;
        while (list2tail->next != nullptr) 
            list2tail = list2tail->next;
        
        list2tail->next = anext;

        return list1;
    }
};