/*
    Given an integer array nums that may contain duplicates, return all possible subsets (the power set). The solution set must not contain duplicate subsets. Return the 
    solution in any order.

    Example 1:
    Input: nums = [1,2,2]
    Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int index, vector<int>& nums, vector<int>& arr, vector<vector<int>>& ans) {
        ans.push_back(arr);

        for(int i=index; i<nums.size(); i++) {
            if(i != index && nums[i] == nums[i-1])
                continue;

            arr.push_back(nums[i]);
            solve(i+1, nums, arr, ans);
            arr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> arr;
        int index = 0;

        solve(index, nums, arr, ans);

        return ans;
    }
};