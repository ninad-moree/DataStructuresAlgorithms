/*
    Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal. In one move, you can increment or decrement an element 
    of the array by 1. Test cases are designed so that the answer will fit in a 32-bit integer.

    Example 1:
    Input: nums = [1,2,3]
    Output: 2
    Explanation: Only two moves are needed (remember each move increments or decrements one element): [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int num;
        if(n % 2 == 1) 
            num = nums[n / 2];
        else 
            num = (nums[n/2 - 1] + nums[n/2]) / 2;
        
        int ans = 0;

        for(auto i : nums) 
            ans += abs(num - i);

        return ans;
    }
};