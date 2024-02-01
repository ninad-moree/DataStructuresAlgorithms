/*
    You are given a 0-indexed integer array nums.
    Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all 
    such triplets have a negative value, return 0.
    The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

    Example 1:
    Input: nums = [12,6,1,2,7]
    Output: 77
    Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
    It can be shown that there are no ordered triplets of indices with a value greater than 77. 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        long long curr = 0;

        for(int i=0;i<nums.size();i++) {
            for(int j=i+1;j<nums.size();j++) {
                for(int k=j+1;k<nums.size();k++) {
                    curr = (long long)nums[i]*nums[k] - (long long)nums[j]*nums[k];
                    ans = max(ans, curr); 
                }
            }
        }

        return ans;
    }
};