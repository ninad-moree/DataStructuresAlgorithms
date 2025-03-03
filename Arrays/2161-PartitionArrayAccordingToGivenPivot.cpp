/*
    You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied: 
    Every element less than pivot appears before every element greater than pivot. 
    Every element equal to pivot appears in between the elements less than and greater than pivot. T
    he relative order of the elements less than pivot and the elements greater than pivot is maintained.
    Return nums after the rearrangement.

    Example 1:
    Input: nums = [9,12,5,10,14,3,10], pivot = 10
    Output: [9,5,3,10,10,12,14]
    Explanation: 
    The elements 9, 5, and 3 are less than the pivot so they are on the left side of the array.
    The elements 12 and 14 are greater than the pivot so they are on the right side of the array.
    The relative ordering of the elements less than and greater than pivot is also maintained. [9, 5, 3] and [12, 14] are the respective orderings.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int idx = 0;
        int piv = 0;

        for(auto i : nums) {
            if(i < pivot) {
                ans[idx] = i;
                idx++;
            } else if (i == pivot)
                piv++;
        }

        while(piv > 0) {
            ans[idx] = pivot;
            piv--;
            idx++;
        }

        for(auto i : nums) {
            if(i > pivot) {
                ans[idx] = i;
                idx++;
            }
        }

        return ans;
    }
};