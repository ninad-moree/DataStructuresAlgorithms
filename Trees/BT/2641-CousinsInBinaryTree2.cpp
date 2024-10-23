/*
    Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values. Two nodes of a binary tree are
    cousins if they have the same depth with different parents. Return the root of the modified tree.

    Example 1:
    Input: root = [5,4,9,1,10,null,7]
    Output: [0,0,0,7,7,null,11]
    Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
    - Node with value 5 does not have any cousins so its sum is 0.
    - Node with value 4 does not have any cousins so its sum is 0.
    - Node with value 9 does not have any cousins so its sum is 0.
    - Node with value 1 has a cousin with value 7 so its sum is 7.
    - Node with value 10 has a cousin with value 7 so its sum is 7.
    - Node with value 7 has cousins with values 1 and 10 so its sum is 11.
*/

#include<bits/stdc++.h>
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        deque<TreeNode*> dq;
        dq.push_back(root);

        while(!dq.empty()) {
            int s = dq.size();
            int levelSum = 0;

            for(auto i : dq)
                levelSum += (i->left ? i->left->val : 0) + (i->right ? i->right->val : 0);

            for(int i=0; i<s; i++) {
                TreeNode* front = dq.front();
                dq.pop_front();

                int sum = levelSum;

                if(front->left)
                    sum -= front->left->val;
                if(front->right)
                    sum -= front->right->val;

                if(front->left) {
                    dq.push_back(front->left);
                    front->left->val = sum;
                }
                if(front->right) {
                    dq.push_back(front->right);
                    front->right->val = sum;
                }
            }
        }

        root->val = 0;
        return root;
    }
};