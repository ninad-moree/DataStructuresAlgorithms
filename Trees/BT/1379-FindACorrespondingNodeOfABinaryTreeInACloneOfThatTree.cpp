/*
    Given two binary trees original & cloned & given a reference to a node target in the original tree. The cloned tree is a copy of the original tree. Return a reference to the
    same node in the cloned tree. Note that you aren't allowed to change any of the two trees or the target node & the answer must be a reference to a node in the cloned tree.

    Example 1:
    Input: tree = [7,4,3,null,null,6,19], target = 3
    Output: 3
    Explanation: The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.
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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> qo;
        qo.push(original);

        queue<TreeNode*> qc;
        qc.push(cloned);

        while(!qo.empty()) {
            auto fo = qo.front();
            qo.pop();

            auto fc = qc.front();
            qc.pop();

            if(fo == target)
                return fc;

            if(fo->left) {
                qo.push(fo->left);
                qc.push(fc->left);
            }
            if(fo->right) {
                qo.push(fo->right);
                qc.push(fc->right);
            }
        }

        return NULL;
    }
};