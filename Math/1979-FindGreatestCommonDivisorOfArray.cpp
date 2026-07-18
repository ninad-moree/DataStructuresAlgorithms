/*
    Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums. The greatest common divisor of two numbers is the largest 
    positive integer that evenly divides both numbers.

    Example 1:
    Input: nums = [2,5,6,9,10]
    Output: 2
    Explanation: The smallest number in nums is 2. The largest number in nums is 10. The greatest common divisor of 2 and 10 is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[0];

        for(auto i : nums) {
            mini = min(mini, i);
            maxi = max(maxi, i);
        }

        while(mini) {
            int rem = maxi % mini;
            maxi = mini;
            mini = rem;
        }

        return maxi;
    }
};