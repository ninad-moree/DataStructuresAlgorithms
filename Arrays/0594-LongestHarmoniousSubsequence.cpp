/*
    We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
    Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

    Example 1:
    Input: nums = [1,3,2,2,5,2,3,7]
    Output: 5
    Explanation: The longest harmonious subsequence is [3,2,2,2,3].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        int i = 0;
        int j = 1;

        while(i < j && j < nums.size()) {
            while(nums[j] - nums[i] > 1)
                i++;

            if(nums[j] - nums[i] == 1)
                ans = max(ans, j - i + 1);
                
            j++;
        }

        return ans;
    }
};