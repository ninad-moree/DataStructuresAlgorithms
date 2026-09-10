/*
    You are given two integer arrays nums and target, each of length n, where nums[i] is the current value at index i and target[i] is the desired value at index i. You may 
    perform the following operation any number of times (including zero): Choose an integer value x Find all maximal contiguous segments where nums[i] == x (a segment is 
    maximal if it cannot be extended to the left or right while keeping all values equal to x) For each such segment [l, r], update simultaneously: nums[l] = target[l], 
    nums[l + 1] = target[l + 1], ..., nums[r] = target[r]. Return the minimum number of operations required to make nums equal to target.

    Example 1:
    Input: nums = [1,2,3], target = [2,1,3]
    Output: 2
    Explanation:​​​​​​​ Choose x = 1: maximal segment [0, 0] updated -> nums becomes [2, 2, 3] Choose x = 2: maximal segment [0, 1] updated (nums[0] stays 2, nums[1] becomes 1) -> 
    nums becomes [2, 1, 3]. Thus, 2 operations are required to convert nums to target.​​​​​​​​​​​​​​
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_set<int> s;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != target[i])
                s.insert(nums[i]);
        }

        return s.size();
    }
};