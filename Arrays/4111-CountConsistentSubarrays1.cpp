/*
    You are given an integer array nums. A subarray is called consistent if the bitwise AND of all its elements is equal to the minimum value of the subarray.
    Return the number of consistent subarrays in nums.

    Example 1:
    Input: nums = [5,3,1,2]
    Output: 6
    Explanation: The number of consistent subarrays is 6.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int ans = 0;

        for(int i=0; i<nums.size(); i++) {
            int mini = INT_MAX;
            int andE = -1;

            for(int j=i; j<nums.size(); j++) {
                mini = min(mini, nums[j]);
                andE = andE & nums[j];

                if(mini == andE)
                    ans++;
            }   
        }

        return ans;
    }
};