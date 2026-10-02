/*
    You are given an integer array nums. You may rearrange the elements in any order. The alternating score of an array arr is defined as:
    score = arr[0]2 - arr[1]2 + arr[2]2 - arr[3]2 + ... Return an integer denoting the maximum possible alternating score of nums after rearranging its elements.

    Example 1:
    Input: nums = [1,2,3]
    Output: 12
    Explanation: A possible rearrangement for nums is [2,1,3], which gives the maximum alternating score among all possible rearrangements. The alternating score is calculated 
    as: score = 22 - 12 + 32 = 4 - 1 + 9 = 12
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(auto& i : nums) {
            if(i < 0)
                i = i * (-1);
        }

        sort(nums.begin(), nums.end());

        int l = 0;
        int r = nums.size() - 1;
        int n = nums.size();
        long long ans = 0;

        while(l < r) {
            long long l2 = nums[l] * nums[l];
            long long r2 = nums[r] * nums[r];

            ans += r2;
            ans -= l2;

            l++;
            r--;
        }

        if(n % 2 == 1) {
            long long l2 = nums[l] * nums[l];
            ans += l2;
        }

        return ans;
    }
};