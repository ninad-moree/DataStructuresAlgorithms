/*
    Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

    Example 1:
    Input: nums = [1,1,2]
    Output: [[1,1,2], [1,2,1], [2,1,1]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int> nums, set<vector<int>>& st,  int index) {
        if(index >= nums.size()) {
            st.insert(nums);
            return;
        }

        for(int i=index; i<nums.size(); i++) {
            swap(nums[index], nums[i]);

            solve(nums, st, index+1);

            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) { 
        vector<vector<int>> ans;
        set<vector<int>> st;
        int index = 0;

        solve(nums, st, index);

        for(auto i : st)
            ans.push_back(i);

        return ans;
    }
};