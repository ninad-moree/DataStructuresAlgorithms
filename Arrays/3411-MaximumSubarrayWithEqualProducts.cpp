/*
    You are given an array of positive integers nums. An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr), where:
    prod(arr) is the product of all elements of arr. gcd(arr) is the GCD of all elements of arr. lcm(arr) is the LCM of all elements of arr.
    Return the length of the longest product equivalent subarray of nums.

    Example 1:
    Input: nums = [1,2,1,2,1,1,1]
    Output: 5
    Explanation: The longest product equivalent subarray is [1, 2, 1, 1, 1], where prod([1, 2, 1, 1, 1]) = 2, gcd([1, 2, 1, 1, 1]) = 1, and lcm([1, 2, 1, 1, 1]) = 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lcm(int a, int b) {
        return (a / __gcd(a, b)) * b;
    }

    int maxLength(vector<int>& nums) {
        int ans = 0;

        for(int i=0; i<nums.size(); i++) {
            long long prod = nums[i];
            long long gcdV = nums[i];
            long long lcmV = nums[i];

            for(int j=i+1; j<nums.size(); j++) {
                prod = prod * nums[j];
                gcdV = __gcd(gcdV, 1LL * nums[j]);
                lcmV = lcm(lcmV, nums[j]);

                if(prod > gcdV * lcmV)
                    break;

                if(prod == gcdV * lcmV)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};