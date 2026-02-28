/*
    Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.

    Example 1:
    Input: n = 1
    Output: 1
    Explanation: "1" in binary corresponds to the decimal value 1. 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int bitLength = 0;

        for(int i = 1; i <= n; i++) {
            if((i & (i - 1)) == 0) 
                bitLength++;

            ans = ((ans << bitLength) % MOD + i) % MOD;
        }

        return ans;
    }
};