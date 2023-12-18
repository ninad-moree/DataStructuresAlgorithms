/*
    The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d).
    For example, the product difference between (5, 6) and (2, 7) is (5 * 6) - (2 * 7) = 16.
    Given an integer array nums, choose four distinct indices w, x, y, and z such that the product 
    difference between pairs (nums[w], nums[x]) and (nums[y], nums[z]) is maximized.

    Return the maximum such product difference.

    Example 1:
    Input: nums = [5,6,2,7,4]
    Output: 34
    Explanation: We can choose indices 1 and 3 for the first pair (6, 7) and indices 2 and 4 for the second pair (2, 4).
    The product difference is (6 * 7) - (2 * 4) = 34.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // return (nums[nums.size()-1]*nums[nums.size()-2]) - (nums[0]*nums[1]);

        int fl=0, sl=0, fs=INT_MAX, ss=INT_MAX;

        for(auto n : nums) {
            if(n<fs) {
                ss = fs;
                fs = n;
            } 
            else if (n<ss)
                ss = n;
            
            if(n > fl) {
                sl = fl;
                fl = n;
            }
            else if(n>sl) 
                sl = n;
        }

        return (fl*sl) - (fs*ss);
    }
};