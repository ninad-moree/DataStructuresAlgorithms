/*
    An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
    You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that 
    subarray nums[fromi..toi] is special or not.
    Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.
    
    Example 1:
    Input: nums = [3,4,1,2,6], queries = [[0,4]]
    Output: [false]
    Explanation:
    The subarray is [3,4,1,2,6]. 2 and 6 are both even.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> prefix;
        vector<bool> ans;

        prefix.push_back(0);

        for(int i=1; i<n; i++) {
            if(nums[i]%2 == nums[i-1]%2)
                prefix.push_back(1);
            else
                prefix.push_back(0);
        }

        vector<int> preSum(n);
        preSum[0] = 0;
        for(int i=1; i<n; i++) 
            preSum[i] = preSum[i-1] + prefix[i];

        for(int i=0; i<queries.size(); i++) {
            int from = queries[i][0];
            int to = queries[i][1];

            if(preSum[to] - preSum[from] >= 1)
                ans.push_back(false);
            else
                ans.push_back(true);
        }

        return ans;
    }
};
