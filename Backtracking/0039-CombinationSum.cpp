/*
    Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to 
    target. You may return the combinations in any order. The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
    frequency of at least one of the chosen numbers is different. The test cases are generated such that the number of unique combinations that sum up to target is less 
    than 150 combinations for the given input.

    Example 1:
    Input: candidates = [2,3,6,7], target = 7
    Output: [[2,2,3],[7]]
    Explanation: 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times. 7 is a candidate, and 7 = 7. These are the only two combinations.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int index, vector<int>& arr, int target, vector<vector<int>>& ans, vector<int> candidates) {
        if(index >= candidates.size()) {
            if(target == 0)
                ans.push_back(arr);
            return;
        }

        if(candidates[index] <= target) {
            arr.push_back(candidates[index]);
            solve(index, arr, target - candidates[index], ans, candidates);
            arr.pop_back();
        }

        solve(index+1, arr, target, ans, candidates);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        int index = 0;

        solve(index, arr, target, ans, candidates);

        return ans;
    }
};