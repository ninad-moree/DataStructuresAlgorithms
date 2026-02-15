/*
    Given an integer array nums of unique elements, return all possible subsets (the power set). The solution set must not contain duplicate subsets. Return the solution in any 
    order.

    Example 1:
    Input: nums = [1,2,3]
    Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int index, vector<int>& arr, vector<int> nums, int n, vector<vector<int>>& ans) {
        if(index >= n) {
            ans.push_back(arr);
            return;
        }

        arr.push_back(nums[index]);
        solve(index+1, arr, nums, n, ans);
        arr.pop_back();

        solve(index+1, arr, nums, n, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;

        int index = 0;
        int n = nums.size();

        solve(index, arr, nums, n, ans);

        return ans;
    }

    /* BIT MANIPULATION*/
    vector<vector<int>> subsetsBit(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        int subSets = 1 << n;

        for(int num=0; num<subSets; num++) {
            vector<int> res;

            for(int i=0; i<n; i++) {
                if(num & (1 << i))
                    res.push_back(nums[i]);
            }

            ans.push_back(res);
        }

        return ans;
    }
};