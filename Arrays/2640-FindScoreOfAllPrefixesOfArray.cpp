/*
    We define the conversion array conver of an array arr as follows:
        conver[i] = arr[i] + max(arr[0..i]) where max(arr[0..i]) is the maximum value of arr[j] over 0 <= j <= i.
    We also define the score of an array arr as the sum of the values of the conversion array of arr.
    Given a 0-indexed integer array nums of length n, return an array ans of length n where ans[i] is the score of the prefix nums[0..i].

    Example 1:
    Input: nums = [2,3,7,5,10]
    Output: [4,10,24,36,56]
    Explanation: 
    For the prefix [2], the conversion array is [4] hence the score is 4
    For the prefix [2, 3], the conversion array is [4, 6] hence the score is 10
    For the prefix [2, 3, 7], the conversion array is [4, 6, 14] hence the score is 24
    For the prefix [2, 3, 7, 5], the conversion array is [4, 6, 14, 12] hence the score is 36
    For the prefix [2, 3, 7, 5, 10], the conversion array is [4, 6, 14, 12, 20] hence the score is 56
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans(nums.size());

        long long maxi = 0;
        long long sum = 0;

        for(int i=0; i<nums.size(); i++) {
            maxi = max(maxi, (long long)nums[i]);
            sum += ((long long)nums[i] + maxi);
            ans[i] = sum;
        }

        return ans;
    }
};