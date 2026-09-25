/*
    You are given an integer array nums. You must replace exactly one element in the array with any integer value in the range [-105, 105] (inclusive). After performing this 
    single replacement, determine the maximum possible product of any three elements at distinct indices from the modified array. Return an integer denoting the maximum product
    achievable.

    Example 1:
    Input: nums = [-5,7,0]
    Output: 3500000
    Explanation: Replacing 0 with -105 gives the array [-5, 7, -105], which has a product (-5) * 7 * (-105) = 3500000. The maximum product is 3500000.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int maxi1 = -1e5;
        int maxi2 = -1e5;

        for(auto i : nums) {
            long long n = abs(i);

            if(n >= maxi1) {
                maxi2 = maxi1;
                maxi1 = n;
            } else if(n > maxi2)
                maxi2 = n;
        }

        return 1LL * 1e5 * maxi1 * maxi2;
    }
};