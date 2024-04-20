/*
    Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary 
    tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

        1
        /     \
    2       3
    /  \    /   \
    4    5  6   7
    Top view will be: 4 2 1 3 7
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution {
    public:
    vector<int> topView(Node *root) {
        queue<pair<Node*, int>> q; // stores node and it's horizontal dist
        vector<int> ans;
        map<int, int> mp;
        
        q.push({root, 0});
        
        while(!q.empty()) {
            pair<Node*, int> front = q.front();
            q.pop();
            
            Node* node = front.first;
            int hd = front.second;
            
            if(mp.find(hd) == mp.end())
                mp[hd] = node->data;
            
            if(node->left)
                q.push({node->left, hd-1});
            if(node->right)
                q.push({node->right, hd+1});
        }
        
        for(auto i : mp)
            ans.push_back(i.second);
        
        return ans;
    }
};