/*
    Given an integer array nums and an integer k, return the number of subarrays of nums where the least common multiple of the subarray's 
    elements is k. A subarray is a contiguous non-empty sequence of elements within an array.
    The least common multiple of an array is the smallest positive integer that is divisible by all the array elements.

    Example 1:
    Input: nums = [3,6,2,7,1], k = 6
    Output: 4
    Explanation: The subarrays of nums where 6 is the least common multiple of all the subarray's elements are:
    - [3,6,2,7,1]
    - [3,6,2,7,1]
    - [3,6,2,7,1]
    - [3,6,2,7,1]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lcm(int a, int b) {
        return (a / __gcd(a, b)) * b;
    }
    
    int subarrayLCM(vector<int>& nums, int k) {
        int ans = 0;

        for(int i=0; i<nums.size(); i++) {
            int n = nums[i];
            if(n == k)
                ans++;
            for(int j=i+1; j<nums.size() && k%nums[j]==0; j++) {
                n = lcm(nums[j], n);
                if(n == k)
                    ans++;
            }
        }

        return ans;
    }
};