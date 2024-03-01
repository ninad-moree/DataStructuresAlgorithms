/*
    Given the head of a linked list head, in which each node contains an integer value.
    Between every pair of adjacent nodes, insert a new node with a value equal to the greatest 
    common divisor of them.
    Return the linked list after insertion.
    The greatest common divisor of two numbers is the largest positive integer that evenly divides 
    both numbers.

    Example 1:
    Input: head = [18,6,10,3]
    Output: [18,6,6,2,10,1,3]
    Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the 
    linked list after inserting the new nodes (nodes in blue are the inserted nodes).
    - We insert the greatest common divisor of 18 and 6 = 6 between the 1st and the 2nd nodes.
    - We insert the greatest common divisor of 6 and 10 = 2 between the 2nd and the 3rd nodes.
    - We insert the greatest common divisor of 10 and 3 = 1 between the 3rd and the 4th nodes.
    There are no more adjacent nodes, so we return the linked list.
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
    int gcd(int a, int b) {
        if(b==0) return a;
        else  return gcd(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* temp=head;
        while(temp->next) {
            int v1 = temp->val;
            int v2 = temp->next->val;
            int cd = gcd(v1,v2);
            
            ListNode* newNode = new ListNode(cd);
            newNode->next = temp->next;
            temp->next = newNode;
            temp=newNode->next;
        }
        return head;
    }
    
};