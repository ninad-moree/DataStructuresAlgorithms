/*
    Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is 
    impossible to form any triangle of a non-zero area, return 0.

    Example 1:
    Input: nums = [2,1,2]
    Output: 5
    Explanation: You can form a triangle with three side lengths: 1, 2, and 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());

        for(int i=0; i<nums.size()-2; i++) {
            if(nums[i] < nums[i+1] + nums[i+2])
                return nums[i] + nums[i+1] + nums[i+2];
        }

        return 0;
    }
};