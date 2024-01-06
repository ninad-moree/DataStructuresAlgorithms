/*
    Given an array nums of positive integers. Your task is to select some subset of nums, 
    multiply each element by an integer and add all these numbers. The array is said to 
    be good if you can obtain a sum of 1 from the array by any possible subset and multiplicand.
    Return True if the array is good otherwise return False.
    
    Example 1:
    Input: nums = [12,5,7,23]
    Output: true
    Explanation: Pick numbers 5 and 7.
    5*3 + 7*(-2) = 1
*/

#include<bits/stdc++.h>
#include <numeric>
#include <algorithm> 
using namespace std;

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int result = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            result = __gcd(result, nums[i]);
            if (result == 1) 
                return true;
        }
        
        return result == 1;
    }
};


