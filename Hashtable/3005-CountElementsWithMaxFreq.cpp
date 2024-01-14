/*
    You are given an array nums consisting of positive integers.
    Return the total frequencies of elements in nums such that those elements all have the maximum frequency.
    The frequency of an element is the number of occurrences of that element in the array.

    Example 1:
    Input: nums = [1,2,2,3,1,4]
    Output: 4
    Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
    So the number of elements in the array with maximum frequency is 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(int i=0;i<nums.size();i++)
                mp[nums[i]]++;
        
        int maxFreq = 0;
        for(auto i : mp){
            if(i.second >= maxFreq)
                maxFreq = i.second;
        }

        int ans = 0;
        for(auto i : mp){
            if(i.second == maxFreq)
                ans += maxFreq;
        }
        
        return ans;
    }
};