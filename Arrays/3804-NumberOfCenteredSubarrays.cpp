/*
    You are given an integer array nums. A subarray of nums is called centered if the sum of its elements is equal to at least one element within that same subarray.
    Return the number of centered subarrays of nums.

    Example 1:
    Input: nums = [-1,1,0]
    Output: 5
    Explanation: All single-element subarrays ([-1], [1], [0]) are centered. The subarray [1, 0] has a sum of 1, which is present in the subarray. The subarray [-1, 1, 0] has a
    sum of 0, which is present in the subarray. Thus, the answer is 5.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=0; i<n; i++) {
            unordered_map<int, int> mp;
            int sum = 0;

            for(int j=i; j<n; j++) {
                mp[nums[j]]++;
                sum += nums[j];

                if(mp.find(sum) != mp.end())
                    ans++;
            }
        }

        return ans;
    }
};