/*
    You are given an integer array nums of length n and a binary string s of the same length. Initially, your score is 0. Each index i where s[i] = '1' contributes nums[i] to 
    the score. You may perform any number of operations (including zero). In one operation, you may choose an index i such that 0 <= i < n - 1, where s[i] = '0', and s[i + 1] 
    = '1', and swap these two characters. Return an integer denoting the maximum possible score you can achieve.

    Example 1:
    Input: nums = [2,1,5,2,3], s = "01010"
    Output: 7
    Explanation: We can perform the following swaps: Swap at index i = 0: "01010" changes to "10010" Swap at index i = 2: "10010" changes to "10100"
    Positions 0 and 2 contain '1', contributing nums[0] + nums[2] = 2 + 5 = 7. This is maximum score achievable.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        int n = nums.size();
        int i = 0;
        long long ans = 0;

        priority_queue<long long> pq;
        
        while(i < n) {
            pq.push(nums[i]);

            if(s[i] == '1') {
                ans += pq.top();
                pq.pop();
            }

            i++;
        }

        return ans;
    }
};