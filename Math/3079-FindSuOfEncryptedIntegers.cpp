/*
    You are given an integer array nums containing positive integers. We define a function encrypt such that encrypt(x) 
    replaces every digit in x with the largest digit in x. For example, encrypt(523) = 555 and encrypt(213) = 333.
    Return the sum of encrypted elements.

    Example 1:
    Input: nums = [1,2,3]
    Output: 6
    Explanation: The encrypted elements are [1,2,3]. The sum of encrypted elements is 1 + 2 + 3 == 6.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int encrypt(int n) {
        vector<int> res;
        int maxi = 0;
        
        while(n > 0) {
            int digit = n%10;
            res.push_back(digit);
            maxi = max(maxi, digit);
            n = n/10;
        }

        for(int i=0; i<res.size(); i++)
            res[i] = maxi;

        int newNum = 0;
        for(auto i : res) 
            newNum = newNum*10 + i;
        
        return newNum; 
    }

    int sumOfEncryptedInt(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            int maxi = 0;

            maxi = encrypt(nums[i]);
            nums[i] = maxi;
        }

        int ans = 0;
        for(auto i : nums)
            ans += i;

        return ans;
    }
};