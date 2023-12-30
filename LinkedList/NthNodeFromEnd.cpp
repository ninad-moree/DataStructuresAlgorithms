/*
    Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

    Example 1:
    Input: N = 2, LinkedList: 1->2->3->4->5->6->7->8->9
    Output: 8
    Explanation: In the first example, there are 9 nodes in linked list and we need to find 2nd node from end. 2nd node from end is 8.  
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution{
public:
    int getNthFromLast(Node *head, int n)
    {
           // Your code here
           int len = 0;
           Node* temp = head;
           while(temp) {
               len++;
               temp = temp->next;
           }

           if(n>len)
            return -1;
            
           temp = head;
           int cnt = 0;
           
           while(cnt!=len-n) {
               cnt++;
               temp = temp->next;
           }
           return temp->data;
    }
};