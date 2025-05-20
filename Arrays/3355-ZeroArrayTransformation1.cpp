/*
    You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri]. For each queries[i]:
    Select a subset of indices within the range [li, ri] in nums.
    Decrement the values at the selected indices by 1.
    A Zero Array is an array where all elements are equal to 0.
    Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.

    Example 1:
    Input: nums = [1,0,1], queries = [[0,2]]
    Output: true
    Explanation: For i = 0:
    Select the subset of indices as [0, 2] and decrement the values at these indices by 1. The array will become [0, 0, 0], which is a Zero Array.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n+1);

        for(auto i : queries) {
            int l = i[0];
            int r = i[1];

            diff[l]++;
            if(r + 1 < n)
                diff[r+1]--;
        }

        int cnt = 0;

        for(int i=0; i<n; i++) {
            cnt += diff[i];

            if(nums[i] > cnt)
                return false;
        }

        return true;
    }
};