/*
    Given an n-ary tree, return the level order traversal of its nodes' values. Nary-Tree input serialization is represented in their level order traversal, each group of 
    children is separated by the null value (See examples).

    Example 1:
    Input: root = [1,null,3,2,4,null,5,6]
    Output: [[1],[3,2,4],[5,6]]
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
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
            
        vector<vector<int>> ans;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int s = q.size();
            vector<int> lvl;

            for(int i=0; i<s; i++) {
                auto f = q.front();
                q.pop();

                lvl.push_back(f->val);

                vector<Node*> children = f->children;

                for(int j=0; j<children.size(); j++) {
                    if(children[j] != NULL)
                        q.push(children[j]);
                }
            }

            ans.push_back(lvl);
        }

        return ans;
    }
};