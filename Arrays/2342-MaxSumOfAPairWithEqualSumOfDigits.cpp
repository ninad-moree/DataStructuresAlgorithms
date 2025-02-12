/*
    You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits 
    of the number nums[i] is equal to that of nums[j]. Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and
    j that satisfy the conditions.

    Example 1:
    Input: nums = [18,43,36,13,7]
    Output: 54
    Explanation: The pairs (i, j) that satisfy the conditions are:
    - (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
    - (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
    So the maximum sum that we can obtain is 54.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitSum(int n) {
        int sum = 0;

        while(n > 0) {
            sum += n%10;
            n = n/10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int ans = -1;
        vector<pair<int, int>> p;

        for(int i=0; i<nums.size(); i++) {
            int sum = digitSum(nums[i]);
            p.push_back({sum, nums[i]});
        }

        sort(p.begin(), p.end());

        for(int i=1; i<p.size(); i++) {
            int currDigitSum = p[i].first;
            int prevDigitSum = p[i-1].first;

            if(currDigitSum == prevDigitSum) {
                int currSum = p[i].second + p[i-1].second;
                ans = max(ans, currSum);
            }
        }

        return ans;
    }
};