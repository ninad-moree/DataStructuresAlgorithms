/*
    You are given an integer array nums of even length n. You have to merge the elements of nums in pairs by merging nums[0] with nums[1], nums[2] with nums[3], and so on, until
    nums[n - 2] with nums[n - 1]. Return the minimum value among all the resulting merged integers. To merge two integers, concatenate all the decimal digits of the first 
    integer followed by all the decimal digits of the second integer.

    Example 1:
    Input: nums = [23,55,42,21]
    Output: 2355
    Explanation: Merging nums[0] = 23 and nums[1] = 55 gives 2355. Merging nums[2] = 42 and nums[3] = 21 gives 4221. The minimum value among the merged numbers is 
    min(2355, 4221) = 2355.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;

        for(int i=0; i<n; i+=2) {
            string s1 = to_string(nums[i]);
            string s2 = to_string(nums[i+1]);

            string s = s1 + s2;
            int num = stoi(s);

            mini = min(mini, num);
        }

        return mini;
    }
};