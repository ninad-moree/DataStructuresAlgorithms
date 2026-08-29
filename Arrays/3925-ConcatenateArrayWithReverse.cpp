/*
    You are given an integer array nums of length n. Construct a new array ans of length 2 * n such that the first n elements are the same as nums, and the next n elements are 
    the elements of nums in reverse order. Formally, for 0 <= i <= n - 1: ans[i] = nums[i] ans[i + n] = nums[n - i - 1] Return an integer array ans.

    Example 1:
    Input: nums = [1,2,3]
    Output: [1,2,3,3,2,1]
    Explanation: The first n elements of ans are the same as nums. For the next n = 3 elements, each element is taken from nums in reverse order:
    ans[3] = nums[2] = 3 ans[4] = nums[1] = 2 ans[5] = nums[0] = 1 Thus, ans = [1, 2, 3, 3, 2, 1].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n);
        int j = ans.size() - 1;

        for(int i=0; i<n; i++) {
            ans[i] = nums[i];
            ans[j] = nums[i];
            j--;
        }

        return ans;
    }
};