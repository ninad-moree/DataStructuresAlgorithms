/*
    You are given an integer array nums. Choose exactly one pair of distinct indices i and j. The strength of the pair is defined as (nums[i] * nums[j]) / gcd(nums[i],
    nums[j])2. Return the maximum strength over all possible pairs.

    Example 1:
    Input: nums = [2,3,5]
    Output: 15
    Explanation: Choosing i = 1 and j = 2 gives strength (3 * 5) / gcd(3, 5)2 = 15 / 1 = 15, which is the maximum over all pairs.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        while(b > 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }

        return a;
    }

    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                long long n1 = nums[i];
                long long n2 = nums[j];
                long long g = gcd(n1, n2);

                long long st = 1LL * n1 * n2 / (g * g);

                ans = max(ans, st);
            }
        }

        return ans;
    }
};