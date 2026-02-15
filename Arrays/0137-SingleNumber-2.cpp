/*
    Given an integer array nums where every element appears three times except for one, which appears exactly once. 
    Find the single element and return it.

    Example 1:
    Input: nums = [2,2,3,2]
    Output: 3
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Using BItIdx */
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for(int bitIdx=0; bitIdx<32; bitIdx++) {
            int cnt = 0;

            for(int i=0; i<nums.size(); i++) {
                if(nums[i] & (1 << bitIdx))
                    cnt++;
            }

            if(cnt%3 == 1)
                ans = ans | (1 << bitIdx);
        }

        return ans;
    }

    /* For loop using Sorted array*/
    int singleNumberSortedArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=1; i<nums.size(); i+=3) {
            if(nums[i] != nums[i-1])
                return nums[i-1];
        }

        return nums[n-1];
    }

    /* Bucket Method */
    int singleNumberBuckets(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        int twos = 0;

        for(int i=0; i<n; i++) {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }

        return ones;
    }
};