/*
    Given an integer array nums containing distinct positive integers, find and return any number from the array that is 
    neither the minimum nor the maximum value in the array, or -1 if there is no such number.
    Return the selected integer.

    Example 1:
    Input: nums = [3,2,1,4]
    Output: 2
    Explanation: In this example, the minimum value is 1 and the maximum value is 4. Therefore, either 2 or 3 can be valid answers.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        
        // if(nums.size() <= 2)
        //     return -1;

        // return nums[1];

        if(nums.size() <= 2)
            return -1;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < mini)
                mini = nums[i];
            if(nums[i] > maxi)
                maxi = nums[i];
        }


        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != maxi && nums[i] != mini)
                return nums[i];
        }

        return -1;
    }
};