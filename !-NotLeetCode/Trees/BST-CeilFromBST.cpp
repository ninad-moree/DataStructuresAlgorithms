/*
    Ninja is given a binary search tree and an integer. Now he is given a particular key in the tree and returns its ceil value. 
    Ceil of an integer is the closest integer greater than or equal to a given number.

    Sample Input 1:
    Tree -> 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    key -> 4
    Sample Output 1:
    5
*/

#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode {
    public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
        
    BinaryTreeNode(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int findCeil(BinaryTreeNode *node, int x) {
    BinaryTreeNode* temp = node;

    int ceil = -1;

    while(temp != NULL) {
        if(temp->data == x) {
            ceil = temp->data;
            return ceil;
        }

        if(temp->data < x) 
            temp = temp->right;
        else {
            ceil = temp->data;
            temp = temp->left;
        }
    }

    return ceil;
}