/*
    You are given an integer array nums. Each nums[i] is an encoded integer representing two positive integers xi and yi. To decode nums[i], define:
    widthi = nums[i] % 10. di = floor(nums[i] / 10). xi as the integer formed by the first widthi digits of the decimal representation of di.
    yi as the integer formed by all remaining digits of the decimal representation of di. It is guaranteed that the decimal representation of di contains more than widthi 
    digits. Therefore, both xi and yi contain at least one digit. The decoded value of nums[i] is xiyi. Return the sum of the decoded values of all elements in nums, modulo 
    109 + 7. The floor() function returns the integer part of the division.

    Example 1:
    Input: nums = [231]
    Output: 8
    Explanation: For 231, we have width = 1, d = 23, x = 2, and y = 3. The decoded value of 231 is 23 = 8. Since there is only one element in nums, the sum of the decoded 
    values is 8.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 13 = 1101₂ 8 + 4 + 1
    // 2^13 = 2^8 × 2^4 × 2^1
    long long modPow(long long x, long long y, long long MOD) {
        long long res = 1;

        x %= MOD;

        while (y > 0) {
            if (y & 1) // checks whether y is odd.
                res = (res * x) % MOD;

            x = (x * x) % MOD;
            y >>= 1; // Divide y by 2.
        }

        return res;
    }

    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
        long long MOD = 1e9 + 7;
        int ans = 0;

        for(int i=0; i<n; i++) {
            long long num = nums[i];
            int width = num % 10;
            long long d = num / (1LL * 10);

            string str = to_string(d);
            string x1 = str.substr(0, width);
            string y1 = str.substr(width);

            long long x = stoll(x1);
            long long y = y1.empty() ? 0 : stoll(y1);

            long long int res = modPow(x, y, MOD);

            ans = (ans + res) % MOD;
        }

        return ans;
    }
};