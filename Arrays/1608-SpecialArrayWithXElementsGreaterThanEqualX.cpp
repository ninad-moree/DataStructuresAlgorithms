/*
    You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.
    Notice that x does not have to be an element in nums.
    Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.

    Example 1:
    Input: nums = [3,5]
    Output: 2
    Explanation: There are 2 values (3 and 5) that are greater than or equal to 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
       int s = nums.size();

       for(int i=0; i<=s; i++)  {
            int curr = i;
            int count = 0;

            for(int j=0; j<s;j++) {
                if(nums[j ] >= curr )
                    count++;
            }

            if(count== curr)
                return curr;
        }

        return -1;
    }  
};