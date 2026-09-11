/*
    You are given an integer array nums and an integer k. Return the minimum length of a subarray whose sum of the distinct values present in that subarray (each value counted 
    once) is at least k. If no such subarray exists, return -1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int i = 0; 
        int j = 0;
        int sum = 0;
        int ans = INT_MAX;

        while(j < nums.size()) {
            if(mp.find(nums[j]) == mp.end())
                sum += nums[j];

            mp[nums[j]]++;

            while(sum >= k) {
                ans = min(ans, j - i + 1);

                mp[nums[i]]--;

                if(mp[nums[i]] == 0) {
                    sum -= nums[i];
                    mp.erase(nums[i]);
                }

                i++;
            }

            j++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};