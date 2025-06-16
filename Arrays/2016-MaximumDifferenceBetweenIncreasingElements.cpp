/*
    Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 
    0 <= i < j < n and nums[i] < nums[j]. Return the maximum difference. If no such i and j exists, return -1.

    Example 1:
    Input: nums = [7,1,5,4]
    Output: 4
    Explanation: The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
    Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];

        for(int i=1; i<nums.size(); i++) 
            prefix[i] = min(prefix[i-1], nums[i]);

        int ans= INT_MIN;

        for(int i=0; i<nums.size(); i++) {
            int diff = INT_MIN;

            if(nums[i] > prefix[i]) 
                diff = nums[i] - prefix[i];

            ans = max(ans, diff);
        }

        return ans == INT_MIN ? -1 : ans;
    }
};