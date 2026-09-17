/*
    You are given an integer array nums of length n and an integer k. An element in nums is said to be qualified if there exist at least k elements in the array that are 
    strictly greater than it. Return an integer denoting the total number of qualified elements in nums.

    Example 1:
    Input: nums = [3,1,2], k = 1
    Output: 2
    Explanation: The elements 1 and 2 each have at least k = 1 element greater than themselves. ​​​​No element is greater than 3. Therefore, the answer is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> grt(n);
        grt[n-1] = 0;

        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) 
                grt[i] = n - i - 1;
            
            if(nums[i] == nums[i+1])
                grt[i] = grt[i+1];
        }

        int ans = 0;

        for(auto i : grt) {
            if(i >= k)
                ans++;
        }

        return ans;
    }
};