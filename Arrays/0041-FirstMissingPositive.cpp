/*
    Given an unsorted integer array nums, return the smallest missing positive integer.
    You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

    Example 1:
    Input: nums = [1,2,0]
    Output: 3
    Explanation: The numbers in the range [1,2] are all in the array.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       long long maxi = 0;
        for(auto i : nums)
            maxi = max(maxi, (long long)i);

        unordered_map<long long, int> mp;
        for(auto i: nums)
            mp[i]++;

        long long ans = -1;

        for(int i=1; i<=maxi+1; i++) {
            if(mp.find(i) == mp.end()) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};