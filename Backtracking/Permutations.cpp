/*
    Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

    Example 1:
    Input: nums = [1,2,3]
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int> nums, vector<vector<int>>& ans, int index) {
        if(index>=nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int j=index; j<nums.size(); j++) {
            swap(nums[index], nums[j]);
            solve(nums, ans, index+1);
            //backtracking so that main string remains same;
            swap(nums[index], nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        solve(nums, ans, index);
        return ans;
    }
};