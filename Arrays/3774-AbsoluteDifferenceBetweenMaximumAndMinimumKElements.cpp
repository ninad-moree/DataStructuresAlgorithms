/*
    You are given an integer array nums and an integer k. Find the absolute difference between: the sum of the k largest elements in the array; and the sum of the k smallest 
    elements in the array. Return an integer denoting this difference.

    Example 1:
    Input: nums = [5,2,2,4], k = 2
    Output: 5
    Explanation: The k = 2 largest elements are 4 and 5. Their sum is 4 + 5 = 9. The k = 2 smallest elements are 2 and 2. Their sum is 2 + 2 = 4. The absolute difference is 
    abs(9 - 4) = 5.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int maxi = 0;
        int mini = 0;

        for(int i=0; i<k; i++)
            mini += nums[i];

        for(int i=n-1; i>=n-k; i--)
            maxi += nums[i];

        int ans = abs(maxi - mini);

        return ans;
    }
};