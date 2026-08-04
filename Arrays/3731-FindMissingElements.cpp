/*
    You are given an integer array nums consisting of unique integers. Originally, nums contained every integer within a certain range. However, some integers might have gone 
    missing from the array. The smallest and largest integers of the original range are still present in nums. Return a sorted list of all the missing integers in this range. If
    no integers are missing, return an empty list.

    Example 1:
    Input: nums = [1,4,2,5]
    Output: [3]
    Explanation: The smallest integer is 1 and the largest is 5, so the full range should be [1,2,3,4,5]. Among these, only 3 is missing.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int mini = nums[0];
        int maxi = nums[0];

        for(auto i : nums) {
            if(i < mini)
                mini = i;
            if(i > maxi)
                maxi = i;
        }

        vector<int> freq(maxi+1);

        for(auto i : nums) 
            freq[i]++;

        for(int i=mini; i<=maxi; i++) {
            if(freq[i] == 0) 
                ans.push_back(i);
        }

        return ans;
    }
};