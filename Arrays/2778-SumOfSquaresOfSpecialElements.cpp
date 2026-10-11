/*
    You are given a 1-indexed integer array nums of length n.
    An element nums[i] of nums is called special if i divides n, i.e. n % i == 0.
    Return the sum of the squares of all special elements of nums.

    Example 1:
    Input: nums = [1,2,3,4]
    Output: 21
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for(int i=0; i<nums.size(); i++) {
            if(n % (i + 1) == 0)
                ans += (nums[i] * nums[i]);
        }

        return ans;
    }
};