/*
    You are given the root of a binary tree with unique values.
    In one operation, you can choose any two nodes at the same level and swap their values.
    Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.
    The level of a node is the number of edges along the path between it and the root node.

    Example 1:
    Input: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
    Output: 3
    Explanation:
    - Swap 4 and 3. The 2nd level becomes [3,4].
    - Swap 7 and 5. The 3rd level becomes [5,6,8,7].
    - Swap 8 and 7. The 3rd level becomes [5,6,7,8].
    We used 3 operations so return 3.
    It can be proven that 3 is the minimum number of operations needed.
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
    int minimumOperations(TreeNode* root) {
        int ans = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            vector<int> lvl;
            vector<int> arr;
            int n = q.size();

            while(n--) {
                TreeNode* front = q.front();
                q.pop();
                lvl.push_back(front->val);

                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }

            unordered_map<int, int> mp;
            for(int i = 0; i < lvl.size(); i++)
                mp[lvl[i]] = i;
            

            sort(lvl.begin(), lvl.end());
            int i = 0;
            while(i < lvl.size()){
                if(mp[lvl[i]] != i){
                    swap(lvl[i],lvl[mp[lvl[i]]]);
                    ans++;
                }
                else 
                    i++;
            }
        }

        return ans;
    }
};