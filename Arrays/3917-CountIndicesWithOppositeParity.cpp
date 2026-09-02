/*
    You are given an integer array nums of length n. The score of an index i is defined as the number of indices j such that: i < j < n, and nums[i] and nums[j] have different 
    parity (one is even and the other is odd). Return an integer array answer of length n, where answer[i] is the score of index i.

    Example 1:
    Input: nums = [1,2,3,4]
    Output: [2,1,1,0]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int even = 0;
        int odd = 0;

        for(int i=n-1; i>=0; i--) {
            if(nums[i] % 2 == 0) {
                ans[i] = odd;
                even++;
            } else {
                ans[i] = even;
                odd++;
            }
        }

        return ans;
    }
};