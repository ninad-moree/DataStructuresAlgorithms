/*
    You are given a 0-indexed integer array nums. You have to find the maximum sum of a pair of numbers 
    from nums such that the maximum digit in both numbers are equal.
    Return the maximum sum or -1 if no such pair exists.

    Example 1:
    Input: nums = [51,71,17,24,42]
    Output: 88
    Explanation: 
    For i = 1 and j = 2, nums[i] and nums[j] have equal maximum digits with a pair sum of 71 + 17 = 88. 
    For i = 3 and j = 4, nums[i] and nums[j] have equal maximum digits with a pair sum of 24 + 42 = 66.
    It can be shown that there are no other pairs with equal maximum digits, so the answer is 88.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int checkMax(int num) {
        int maxDigit=0;
        while(num>0) {
            int digit = num%10;
            num = num/10;
            maxDigit = max(digit, maxDigit);
        }
        return maxDigit;
    }
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum =0;
        
        for(int i=0;i<n-1;i++) {
            int maX = checkMax(nums[i]);
            for(int j=i+1;j<n;j++) {
                int max2 = checkMax(nums[j]);
                
                if(maX == max2) 
                    sum = nums[i]+nums[j];
                
                ans = max(ans, sum);
            }
        }
        if(ans==0) return -1;
        return ans;
        
    }
};