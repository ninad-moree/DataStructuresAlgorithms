/*
    You are given an integer array nums and two positive integers m and k.
    Return the maximum sum out of all almost unique subarrays of length k of nums. If no such subarray exists, return 0.
    A subarray of nums is almost unique if it contains at least m distinct elements.
    A subarray is a contiguous non-empty sequence of elements within an array.

    Example 1:
    Input: nums = [2,6,7,3,1,7], m = 3, k = 4
    Output: 18
    Explanation: There are 3 almost unique subarrays of size k = 4. These subarrays are [2, 6, 7, 3], [6, 7, 3, 1], 
    and [7, 3, 1, 7]. Among these subarrays, the one with the maximum sum is [2, 6, 7, 3] which has a sum of 18.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long ans=0,curr=0;
        unordered_map<int,int> mp;
        int left=0;

        for(int right=0;right<nums.size();right++){
            curr+=nums[right];
            mp[nums[right]]++;

            if(right-left+1<k)
                continue;
            
            else if(right-left+1>=k){
                if(mp.size()>=m)
                    ans=max(ans,curr);
                
                curr-=nums[left];
                mp[nums[left]]--;

                if(mp[nums[left]]==0)
                    mp.erase(nums[left]);
                
                left++;
            }
        }
        return ans;
    }
};