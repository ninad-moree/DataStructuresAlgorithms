/*
    Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
    Note that you must do this in-place without making a copy of the array.

    Example 1:
    Input: nums = [0,1,0,3,12]
    Output: [1,3,12,0,0]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[l]);
                l++;
            }
        }
    }

    void moveZeroes2(vector<int>& nums) {
        vector<int> ans(nums.size());
        int idx = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0) {
                ans[idx] = nums[i];
                idx++;
            }
        }

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                ans[idx] = nums[i];
                idx++;
            }
        }

        nums = ans;
    }
};