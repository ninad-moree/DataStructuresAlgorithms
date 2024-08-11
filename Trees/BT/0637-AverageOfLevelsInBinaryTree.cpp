/*
    Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual 
    answer will be accepted.
 
    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: [3.00000,14.50000,11.00000]
    Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
    Hence return [3, 14.5, 11].
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;

        if(!root)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            vector<int> lvl;
            int n = q.size();

            for(int i=0; i<n; i++) {
                TreeNode* f = q.front();
                q.pop();
                lvl.push_back(f->val);

                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }

            double avg = 0;
            int m = lvl.size();

            for(auto i : lvl)
                avg += i;
            avg = avg/m;

            ans.push_back(avg);
        }

        return ans;
    }
};