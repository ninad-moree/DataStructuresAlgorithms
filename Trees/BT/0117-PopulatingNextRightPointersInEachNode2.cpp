/*
    Given a binary tree
    struct Node {
        int val;
        Node *left;
        Node *right;
        Node *next;
    }
    Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
    Initially, all next pointers are set to NULL.

    Example 1:
    Input: root = [1,2,3,4,5,null,7]
    Output: [1,#,2,3,#,4,5,7,#]
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();

            for(int i=0; i<n; i++) {
                Node* f = q.front();

                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);

                if(i != n-1) {
                    q.pop();
                    f->next = q.front();
                } else {
                    q.pop();
                    f->next = nullptr;
                }
            }
        }

        return root;
    }
};