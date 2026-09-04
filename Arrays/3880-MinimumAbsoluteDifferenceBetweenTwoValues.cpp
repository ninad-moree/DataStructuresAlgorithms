/*
    You are given an integer array nums consisting only of 0, 1, and 2. A pair of indices (i, j) is called valid if nums[i] == 1 and nums[j] == 2. Return the minimum absolute 
    difference between i and j among all valid pairs. If no valid pair exists, return -1. The absolute difference between indices i and j is defined as abs(i - j).

    Example 1:
    Input: nums = [1,0,0,2,0,1]
    Output: 2
    Explanation: The valid pairs are: (0, 3) which has absolute difference of abs(0 - 3) = 3. (5, 3) which has absolute difference of abs(5 - 3) = 2. Thus, the answer is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        vector<int> fre2;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 2)
                fre2.push_back(i);
        }

        if(fre2.size() == 0)
            return -1;

        int ans = INT_MAX;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 1) {
                for(auto j : fre2)
                    ans = min(ans, abs(i-j));
            }
        }

        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};