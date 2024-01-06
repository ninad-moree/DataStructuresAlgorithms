/*
    Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
    Return the running sum of nums.

    Example 1:
    Input: nums = [1,2,3,4]
    Output: [1,3,6,10]
    Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums.size());

        ans[0] = nums[0];

        for(int i=1;i<nums.size();i++) 
            ans[i] = ans[i-1] + nums[i];
        
        return ans;
    }
};