/*
    You are given an integer array nums. An element nums[i] is considered valid if it satisfies at least one of the following conditions:
    It is strictly greater than every element to its left. It is strictly greater than every element to its right. The first and last elements are always valid.
    Return an array of all valid elements in the same order as they appear in nums.

    Example 1:
    Input: nums = [1,2,4,2,3,2]
    Output: [1,2,4,3,2]
    Explanation: nums[0] and nums[5] are always valid. nums[1] and nums[2] are strictly greater than every element to their left. nums[4] is strictly greater than every element
    to its right. Thus, the answer is [1, 2, 4, 3, 2].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        vector<int> left(n);
        vector<int> right(n);

        left[0] = nums[0];
        int max = nums[0];
        for(int i=1; i<n; i++) {
            if(nums[i] > max) {
                max = nums[i];
                left[i] = nums[i];
            }
        }

        right[n-1] = nums[n-1];
        max = nums[n-1];
        for(int i=n-2; i>=0; i--) {
            if(nums[i] > max) {
                max = nums[i];
                right[i] = nums[i];
            }
        }

        for(int i=0; i<n; i++) {
            if(left[i] == 0 && right[i] == 0)
                continue;

            if(left[i] != 0)
                ans.push_back(left[i]);
            else if(right[i] != 0)
                ans.push_back(right[i]);
        }

        return ans;
    }
};