/*
    Given an integer array nums, return the number of subarrays of length 3 such that the sum of the first and third numbers equals exactly half 
    of the second number.

    Example 1:
    Input: nums = [1,2,1,4,1]
    Output: 1
    Explanation:
    Only the subarray [1,4,1] contains exactly 3 elements where the sum of the first and third numbers equals half the middle number.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0;

        for(int i=0; i<=nums.size()-3; i++) {
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];

            int t = (a+c)*2;

            if(t == b)
                ans++;
        }

        return ans;
    }
};