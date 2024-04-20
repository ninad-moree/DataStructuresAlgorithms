/*
    Given a binary search tree and an integer.Find the floor value of a key in a binary search tree.
    If k lies in BST then is floor equal to k,else floor is equal to previous greater value
    Detailed explanation ( Input/output format, Notes, Images )
    Sample Input 1:
    4
    8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    Sample Output 1:
    2
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

int Floor(BinaryTreeNode *node, int input)
{
	int floor = -1;

    while(node) {
        if(node->data == input) {
            floor = node->data;
            return floor;
        }

        if(input < node->data)
            node = node->left;
        else {
            floor = node->data;
            node = node->right;
        }
    }

    return floor;
}