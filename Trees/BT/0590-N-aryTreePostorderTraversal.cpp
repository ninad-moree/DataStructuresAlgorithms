/*
    Given the root of an n-ary tree, return the postorder traversal of its nodes' values. Nary-Tree input serialization is represented in their level 
    order traversal. Each group of children is separated by the null value (See examples)

    Example 1:
    Input: root = [1,null,3,2,4,null,5,6]
    Output: [5,6,3,2,4,1]
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> res;

    void dfs(Node* node) {
        for(Node* child : node->children) 
            dfs(child);
        
        res.push_back(node->val);
    }

    vector<int> postorder(Node* root) {
        if(!root)
            return {};

        dfs(root);

        return res;
    }
};