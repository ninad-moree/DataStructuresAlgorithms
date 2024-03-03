/*
    You are given an integer array nums. We consider an array good if it is a permutation of an array base[n].
    base[n] = [1, 2, ..., n - 1, n, n] (in other words, it is an array of length n + 1 which contains 1 to n - 1 
    exactly once, plus two occurrences of n). For example, base[1] = [1, 1] and base[3] = [1, 2, 3, 3].
    Return true if the given array is good, otherwise return false.
    Note: A permutation of integers represents an arrangement of these numbers.

    Example 1:
    Input: nums = [2, 1, 3]
    Output: false
    Explanation: Since the maximum element of the array is 3, the only candidate n for which this array could be a 
    permutation of base[n], is n = 3. However, base[3] has four elements but array nums has three. Therefore, it can 
    not be a permutation of base[3] = [1, 2, 3, 3]. So the answer is false.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int maxi = nums[nums.size()-1];

        if(n != maxi+1)
            return false;

        bool ans = true;
        for(int i=0; i<n-2; i++) {
            if(nums[i+1] != nums[i]+1)
                ans = false;
        }
        
        if(nums[n-1]==maxi && nums[n-2]==maxi && ans)
            return true;
        
        return false;
    }
};