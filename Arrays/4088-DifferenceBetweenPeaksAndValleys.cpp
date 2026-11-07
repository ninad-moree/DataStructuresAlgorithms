/*
    You are given an integer array nums of len n. An idx i is called a peak if all of the following conditions hold: 0 < i < n - 1, nums[i] > nums[i - 1], nums[i] > nums[i + 1]
    An index i is called a valley if all of the following conditions hold: 0 < i < n - 1, nums[i] < nums[i - 1] nums[i] < nums[i + 1].
    Return an integer denoting the difference between the sum of all peak values and the sum of all valley values.

    Example 1:
    Input: nums = [1,5,2,4,1,3,0]
    Output: 9
    Explanation: The peak values are nums[1] = 5, nums[3] = 4, and nums[5] = 3. The valley values are nums[2] = 2 and nums[4] = 1.
    The difference between the sum of the peak values and the sum of the valley values is (5 + 4 + 3) - (2 + 1) = 9. Hence, the answer is 9.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int peak = 0;
        int valley = 0;

        for(int i=1; i<nums.size()-1; i++) {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
                peak += nums[i];
            
            if(nums[i] < nums[i-1] && nums[i] < nums[i+1])
                valley += nums[i];
        }

        return peak - valley;
    }
};