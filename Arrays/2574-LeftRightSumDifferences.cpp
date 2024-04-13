/*
    Given a 0-indexed integer array nums, find a 0-indexed integer array answer where:
        answer.length == nums.length.
        answer[i] = |leftSum[i] - rightSum[i]|.
    Where:
    leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
    rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
    Return the array answer.

    Example 1:
    Input: nums = [10,4,8,3]
    Output: [15,1,11,22]
    Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
    The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];

        for(int i=1; i<n; i++) 
            prefix[i] = prefix[i-1] + nums[i];

        for(int i=n-2; i>=0; i--) 
            suffix[i] = suffix[i+1] + nums[i];

        vector<int> ans(n, 0);

        for(int i=0; i<prefix.size(); i++)
            ans[i] = abs(prefix[i] - suffix[i]);
        
        return ans;
    }
};