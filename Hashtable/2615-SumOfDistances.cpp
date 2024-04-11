/*
    You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j 
    such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.
    Return the array arr.

    Example 1:
    Input: nums = [1,3,1,1,2]
    Output: [5,0,3,4,0]
    Explanation: 
    When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5. 
    When i = 1, arr[1] = 0 because there is no other index with value 3.
    When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3. 
    When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4. 
    When i = 4, arr[4] = 0 because there is no other index with value 2.
*/

#include<bits/stdc++.h>
using namespace std;

// HAS TLE

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans;

        for(int i=0; i<nums.size(); i++) {
            int n = nums[i];
            vector<int> idx = mp[n] ;

            long long sum = 0;
            for(int j=0; j<idx.size(); j++) {
                sum += abs(i-idx[j]);
            }
            ans.push_back(sum);
        }

        return ans;
    }
};