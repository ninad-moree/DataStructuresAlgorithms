/*
    Given a binary array nums, return the maximum number of consecutive 1's in the array.

    Example 1:
    Input: nums = [1,1,0,1,1,1]
    Output: 3
    Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int curr = 0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 1) {
                curr++;
                ans = max(ans, curr);
            } else
                curr = 0;
        }

        return ans;
    }
};