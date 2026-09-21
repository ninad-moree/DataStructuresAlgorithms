/*
    You are given an integer array nums. Choose three elements a, b, and c from nums at distinct indices such that the value of the expression a + b - c is maximized. Return an
    integer denoting the maximum possible value of this expression.

    Example 1:
    Input: nums = [1,4,2,5]
    Output: 8
    Explanation: We can choose a = 4, b = 5, and c = 1. The expression value is 4 + 5 - 1 = 8, which is the maximum possible.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int mini = INT_MAX;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > firstMax) {
                secondMax = firstMax;
                firstMax = nums[i];
            } else if (nums[i] > secondMax) 
                secondMax = nums[i];

            mini = min(mini, nums[i]);
        }
        
        int ans = firstMax + secondMax - mini;

        return ans;
    }
};