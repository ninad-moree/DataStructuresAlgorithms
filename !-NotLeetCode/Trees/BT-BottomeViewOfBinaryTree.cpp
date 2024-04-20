/*
    Given a binary tree, print the bottom view from left to right.
    A node is included in bottom view if it can be seen when we look at the tree from bottom.
                        20
                        /    \
                    8       22
                    /   \        \
                5      3       25
                        /   \      
                    10    14
    For the above tree, the bottom view is 5 10 3 14 25.
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
    vector <int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*, int>> q;
        map<int, int> mp;
        
        q.push({root, 0});
        
        while(!q.empty()) {
            pair<Node*, int> front = q.front();
            q.pop();
            
            Node* node = front.first;
            int hd = front.second;
            
            mp[hd] = node->data;
            
            if(node->left)
                q.push({node->left, hd-1});
            if(node->right)
                q.push({node->right, hd+1});
        }
        
        vector<int> ans;
        
        for(auto i : mp)
            ans.push_back(i.second);
        
        return ans;
    }
};