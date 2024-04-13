/*
    You are given the root of a binary tree and a positive integer k. The level sum in the tree is the sum of the values of the nodes that are on 
    the same level. Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.

    Example 1:
    Input: root = [5,8,9,2,1,3,7,4,6], k = 2
    Output: 13
    Explanation: The level sums are the following:
    - Level 1: 5.
    - Level 2: 8 + 9 = 17.
    - Level 3: 2 + 1 + 3 + 7 = 13.
    - Level 4: 4 + 6 = 10.
    The 2nd largest level sum is 13.
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root)
            return -1;
        
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> res;

        while(!q.empty()) {
            int n = q.size();
            long long sum = 0;
            while(n--) {
                TreeNode* front = q.front();
                q.pop();

                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);

                sum += front->val;
            }
            res.push_back(sum);
        }

        sort(res.rbegin(), res.rend());

        if(res.size() < k)
            return -1;
        return res[k-1];
    }
};