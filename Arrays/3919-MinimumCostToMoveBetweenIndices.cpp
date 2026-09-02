/*
    You are given an integer array nums where nums is strictly increasing. For each index x, let closest(x) be the adjacent index y such that abs(nums[x] - nums[y]) is 
    minimized. If both adjacent indices exist and give the same difference, choose the smaller index. From any index x, you can move in two ways:
    To any index y with cost abs(nums[x] - nums[y]), or To closest(x) with cost 1. You are also given a 2D integer array queries, where each queries[i] = [li, ri].
    For each query, calculate the minimum total cost to move from index li to index ri. Return an integer array ans, where ans[i] is the answer for the ith query.
    The absolute difference between two values x and y is defined as abs(x - y).

    Example 1:
    Input: nums = [-5,-2,3], queries = [[0,2],[2,0],[1,2]]
    Output: [6,2,5]
    Explanation:​​​​​​​​​​​​​​​​​​​​ The closest indices are [1, 0, 1] respectively. For [0, 2], the path 0 → 1 → 2 uses a closest move from index 0 to 1 with cost 1 and a move from index 1 to 2 
    with cost |-2 - 3| = 5, giving total 1 + 5 = 6. For [2, 0], the path 2 → 1 → 0 uses two closest moves from index 2 to 1 and from index 1 to 0, each with cost 1, giving 
    total 2. For [1, 2], the direct move from index 1 to index 2 has cost |-2 - 3| = 5, which is optimal. Thus, ans = [6, 2, 5].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> clo(n);
        vector<int> ans(queries.size());
        clo[0] = 1;
        clo[n-1] = n-2;

        for(int i=1; i<n-1; i++) {
            int d1 = abs(nums[i] - nums[i-1]);
            int d2 = abs(nums[i] - nums[i+1]);

            if(d1 < d2)
                clo[i] = i-1;
            else if(d1 > d2)
                clo[i] = i+1;
            else
                clo[i] = min(i-1, i+1);
        }

        vector<int> left(n, 0);  // cost of moving from i to i-1 using closest edges
        vector<int> right(n, 0); // cost of moving from i to i+1 using closest edges,

        // Prefix cost for moving to the right
        for(int i=0; i<n-1; i++) {
            if(clo[i] == i+1)
                right[i+1] = right[i] + 1;
            else
                right[i + 1] = right[i] + (nums[i + 1] - nums[i]);
        }

        // Prefix cost for moving to the left
        for (int i = n - 1; i > 0; i--) {
            if (clo[i] == i - 1)
                left[i - 1] = left[i] + 1;
            else
                left[i - 1] = left[i] + (nums[i] - nums[i - 1]);
        }

        for(int i=0; i<queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            if (l < r) {
                int direct = nums[r] - nums[l];

                int walk = right[r] - right[l];

                ans[i] = min(direct, walk);
            }
            else if (l > r) {
                int direct = nums[l] - nums[r];

                int walk = left[r] - left[l];

                ans[i] = min(direct, walk);
            }
            else 
                ans[i] = 0;
        }
        
        return ans;
    }
};