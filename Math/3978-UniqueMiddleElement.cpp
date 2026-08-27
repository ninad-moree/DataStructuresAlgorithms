/*
    You are given an integer array nums of odd length n. Return true if the middle element of nums appears exactly once in the array. Otherwise return false.

    Example 1:
    Input: nums = [1,2,3]
    Output: true
    Explanation: The middle element of nums is 2, which appears exactly once. Thus, the answer is true.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int mid = n/2;

        int num = nums[mid];
        int cnt = 0;

        for(auto i : nums) {
            if(i == num)
                cnt++;
        }

        return cnt == 1;
    }
};