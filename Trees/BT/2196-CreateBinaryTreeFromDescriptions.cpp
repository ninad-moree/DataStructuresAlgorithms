/*
    You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique 
    values. Furthermore, If isLefti == 1, then childi is the left child of parenti. If isLefti == 0, then childi is the right child of parenti.
    Construct the binary tree described by descriptions and return its root. The test cases will be generated such that the binary tree is valid.

    Example 1:
    Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
    Output: [50,20,80,15,17,19]
    Explanation: The root node is the node with value 50 since it has no parent. The resulting binary tree is shown in the diagram.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes; // val -> node  
        unordered_set<int> children;                  

        for (auto& d : descriptions) {
            int parVal   = d[0];
            int childVal = d[1];
            int isLeft   = d[2];

            if (!nodes.count(parVal))
                nodes[parVal] = new TreeNode(parVal);
            if (!nodes.count(childVal))
                nodes[childVal] = new TreeNode(childVal);

            if (isLeft)
                nodes[parVal]->left  = nodes[childVal];
            else
                nodes[parVal]->right = nodes[childVal];

            children.insert(childVal);
        }

        for (auto i : nodes) {
            int val = i.first;
            TreeNode* node = i.second;
            if (!children.count(val))
                return node;
        }

        return nullptr;
    }
};