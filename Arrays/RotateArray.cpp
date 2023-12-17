/*
    Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

    Example 1:
    Input: nums = [1,2,3,4,5,6,7], k = 3
    Output: [5,6,7,1,2,3,4]
    Explanation:
    rotate 1 steps to the right: [7,1,2,3,4,5,6]
    rotate 2 steps to the right: [6,7,1,2,3,4,5]
    rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans = nums;
        nums.clear();
        int n = ans.size();
        int l = k%n;
        for (int i = n - l; i < n; i++) {
            nums.push_back(ans[i]);
        }
        for (int i = 0; i < n - l; i++) {
            nums.push_back(ans[i]);
        }
    }
};
