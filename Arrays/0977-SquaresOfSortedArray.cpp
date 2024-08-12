/*
    Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

    Example 1:
    Input: nums = [-4,-1,0,3,10]
    Output: [0,1,9,16,100]
    Explanation: After squaring, the array becomes [16,1,0,9,100].
    After sorting, it becomes [0,1,9,16,100].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        vector<int> ans(nums.size());
        int idx = nums.size() - 1;  

        while(l <= r) {
            int l2 = nums[l]*nums[l];
            int r2 = nums[r]*nums[r];

            if(l2 >= r2) {
                ans[idx] = l2;
                l++;
            } else {
                ans[idx] = r2;
                r--;
            }

            idx--;
        }

        return ans;
    }
};