/*
    You are given an integer array nums. A subsequence sub of nums with length x is called valid if it satisfies:
    (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
    Return the length of the longest valid subsequence of nums.

    Example 1:
    Input: nums = [1,2,3,4]
    Output: 4
    Explanation:
    The longest valid subsequence is [1, 2, 3, 4].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++)
            nums[i] = nums[i]%2;
        
        int zero = 0;
        int one = 0;

        for(auto i : nums) {
            if(i == 0)
                zero++;
            else
                one++;
        }

        int even = max(zero, one);
        int odd = 0;
        int flag;

        if(nums[0] == 1)
            flag = 1;
        else
            flag = 0;
        
        for(auto i : nums) {
            if(i == 1 && flag == 1) {
                odd++;
                flag = 0;
            } else {
                if(i == 0 && flag == 0) {
                    odd++;
                    flag = 1;
                } else
                    continue;
            } 
        }

        return max(odd, even);
    }
};