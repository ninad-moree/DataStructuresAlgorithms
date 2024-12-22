/*
    Given a linked list of N nodes such that it may contain a loop.
    A loop here means that the last node of the link list is connected to the node at position X(1-based index). If the link list does not have any loop, X=0.
    Remove the loop from the linked list, if it is present, i.e. unlink the last node which is forming the loop.

    Example 1:
    Input: value[] = {1,3,4} 
    Output: 1
    Explanation: The link list looks like
    1 -> 3 -> 4
        ^    |
        |____|    
    A loop is present. If you remove it successfully, the answer will be 1. 
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node* slow=head;
        Node* fast=head;
        Node* entry=head;
        
        bool flag=false;
        
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
            
            if(fast==slow){
                flag=true;
                break;
            }
        }
        
        if(flag){
            while(entry!=slow){
                entry=entry->next;
                slow=slow->next;
            }
        
            while(fast->next!=slow)
                fast=fast->next;
            
            fast->next=NULL;
        }
    }
};