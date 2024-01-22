/*
    Given the array of integers nums, you will choose two different indices i and j of that array. 
    Return the maximum value of (nums[i]-1)*(nums[j]-1).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return (nums[nums.size()-1] - 1)*(nums[nums.size()-2] - 1);
    }
};