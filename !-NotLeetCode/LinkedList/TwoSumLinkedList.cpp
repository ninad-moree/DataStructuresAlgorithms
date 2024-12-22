/*
    A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference 
    to both the previous and the next nodes in the sequence of nodes.
    You are given a sorted doubly linked list of size 'n', consisting of distinct positive integers, and a number 'k'.
    Find out all the pairs in the doubly linked list with sum equal to 'k'.

    Sample input 1:
    List- 1 2 3 4 9
    k- 5

    Sample output 1
    (1 4), (2 3)
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *prev;
    Node *next;

    Node() {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    Node (int data, Node *next) {
        this->data = data;
        this -> prev = prev;
        this->next = next;
    }
};

vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    if (head == nullptr || head->next == nullptr)
        return {};
    
    Node* temp1 = head;
    Node* temp2 = head;
    while(temp2->next != NULL)
        temp2 = temp2->next;
    
    vector<pair<int,int>> ans;
    while (temp1 != nullptr && temp2 != nullptr && temp1 != temp2 && temp2->next != temp1) {
        int sum = temp1->data + temp2->data;
        if (sum == k) {
            ans.push_back({temp1->data, temp2->data});
            temp1 = temp1->next;
            temp2 = temp2->prev;
        } else if (sum > k) {
            temp2 = temp2->prev;
        } else {
            temp1 = temp1->next;
        }
    }
    return ans;
}