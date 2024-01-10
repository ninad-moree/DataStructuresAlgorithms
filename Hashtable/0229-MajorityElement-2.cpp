/*
    Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

    Example 1:
    Input: nums = [3,2,3]
    Output: [3]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k = n/3;
        unordered_map<int, int> mp;

        for(int i=0;i<n;i++) 
            mp[nums[i]]++;
        
        vector<int>ans;
        for(auto i : mp) {
            if(i.second > k)
                ans.push_back(i.first);
        }
        return ans;
    }
};