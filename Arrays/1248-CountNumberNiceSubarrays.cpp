/*
    Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
    Return the number of nice sub-arrays.

    Example 1:
    Input: nums = [1,1,2,1,1], k = 3
    Output: 2
    Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0; 
        int oddCount = 0; 
        unordered_map<int, int> prefixCounts;  
        
        prefixCounts[0] = 1;  
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 != 0) 
                oddCount++;  
            
            if (prefixCounts.find(oddCount - k) != prefixCounts.end()) 
                count += prefixCounts[oddCount - k];
            
            prefixCounts[oddCount]++;
        }
        
        return count;
    };
}; 