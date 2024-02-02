/*
    You are given an array nums of positive integers and an integer k.
    In one operation, you can remove the last element of the array and add it to your collection.
    Return the minimum number of operations needed to collect elements 1, 2, ..., k.

    Example 1:
    Input: nums = [3,1,5,4,2], k = 2
    Output: 4
    Explanation: After 4 operations, we collect elements 2, 4, 5, and 1, in this order. Our collection 
    contains elements 1 and 2. Hence, the answer is 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int>numbers(k+1, 0);

        int ans = 0;
        int lim = 0;

        for(int i=nums.size()-1; i>=0; i--) {
            if(nums[i] <=k && numbers[nums[i]]==0) {
                numbers[nums[i]]++;
                lim++;
            }
            ans++;
            
            if(lim == k)
                break;
        }

        return ans;
    }
};