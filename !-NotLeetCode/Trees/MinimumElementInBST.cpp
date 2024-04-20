/*
    You are given a Binary Search Tree. Find the minimum value in it.
    For the given input BST is:

        6
        / \
    4    7
    / \
    2   5
    Minimum value in this tree is ‘2’.
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr){};
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

int minVal(Node* root) {	
	Node* temp = root;

	if(!root)
		return -1;

	while(temp->left != NULL) 
		temp = temp->left;
	
	int ans = temp->data;
	return ans;
}