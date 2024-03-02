/*
    You are given an array nums consisting of positive integers.
    We call a subarray of an array complete if the following condition is satisfied:
    The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
    Return the number of complete subarrays.
    A subarray is a contiguous non-empty part of an array.

    Example 1:
    Input: nums = [1,3,1,2,2]
    Output: 4
    Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++) 
            s.insert(nums[i]);

        int dist = s.size();

        if(dist==1)
            return ((nums.size()+1)*nums.size())/2;
        
        int cnt = 0;
        for(int i=0;i<nums.size()-1;i++) {
            set<int> res;
            res.insert(nums[i]);
            if(res.size()==dist) 
                cnt++;
            for(int j=i+1;j<nums.size();j++) {
                res.insert(nums[j]);
                if(res.size()==dist) 
                    cnt++;
            }
        }
        
        return cnt;
    }
};