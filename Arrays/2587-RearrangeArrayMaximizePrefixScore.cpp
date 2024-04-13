/*
    You are given a 0-indexed integer array nums. You can rearrange the elements of nums to any order (including the given order).
    Let prefix be the array containing the prefix sums of nums after rearranging it. In other words, prefix[i] is the sum of the 
    elements from 0 to i in nums after rearranging it. The score of nums is the number of positive integers in the array prefix.
    Return the maximum score you can achieve.

    Example 1:
    Input: nums = [2,-1,0,1,-3,3,-3]
    Output: 6
    Explanation: We can rearrange the array into nums = [2,3,1,-1,-3,0,-3].
    prefix = [2,5,6,5,2,2,-1], so the score is 6.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());

        int ans = 0;

        vector<long long> prefix(nums.size(), 0);
        prefix[0] = nums[0];

        for(int i=1; i<nums.size(); i++) 
            prefix[i] = prefix[i-1] + nums[i];

        for(auto i : prefix) {
            if(i > 0)
                ans++;
        }

        return ans;
    }
};