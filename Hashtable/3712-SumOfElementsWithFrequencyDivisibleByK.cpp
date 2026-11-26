/*
    You are given an integer array nums and an integer k. Return an integer denoting the sum of all elements in nums whose frequency is divisible by k, or 0 if there are no 
    such elements. Note: An element is included in the sum exactly as many times as it appears in the array if its total frequency is divisible by k.

    Example 1:
    Input: nums = [1,2,2,3,3,3,3,4], k = 2
    Output: 16
    Explanation: The number 1 appears once (odd frequency). The number 2 appears twice (even frequency). The number 3 appears four times (even frequency).
    The number 4 appears once (odd frequency). So, the total sum is 2 + 2 + 3 + 3 + 3 + 3 = 16.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto i : nums)
            mp[i]++;

        int ans = 0;

        for(auto i : mp) {
            int num = i.first;
            int freq = i.second;

            if(freq % k == 0) {
                ans += (freq * num);
            }
        }

        return ans;
    }
};