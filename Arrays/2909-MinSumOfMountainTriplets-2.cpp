/*
    You are given a 0-indexed array nums of integers.
    A triplet of indices (i, j, k) is a mountain if:
    i < j < k
    nums[i] < nums[j] and nums[k] < nums[j]
    Return the minimum possible sum of a mountain triplet of nums. If no such triplet exists, return -1.

    Example 1:
    Input: nums = [8,6,1,5,3]
    Output: 9
    Explanation: 
    nums[2] < nums[3] and nums[4] < nums[3]
    And the sum of this triplet is nums[2] + nums[3] + nums[4] = 9. It can be shown that there are no mountain triplets with a sum of less than 9.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int result = INT_MAX;

        vector<int> leftMin(n, INT_MAX);
        for (int i = 1; i < n; i++) {
            leftMin[i] = min(leftMin[i - 1], nums[i - 1]);
        }

        vector<int> rightMin(n, INT_MAX);
        for (int i = n - 2; i >= 0; i--) {
            rightMin[i] = min(rightMin[i + 1], nums[i + 1]);
        }

        for (int j = 1; j < n - 1; j++) {
            if (leftMin[j] < nums[j] && rightMin[j] < nums[j]) 
                result = min(result, leftMin[j] + nums[j] + rightMin[j]);
        }

        return (result == INT_MAX) ? -1 : result;
    }
};