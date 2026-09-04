/*
    You are given three integers n, pos, and k. There are n people standing in a line indexed from 0 to n - 1. Each person independently chooses a direction:
    'L': visible only to people on their right 'R': visible only to people on their left. A person at index pos sees others as follows: A person i < pos is visible if and only 
    if they choose 'L'. A person i > pos is visible if and only if they choose 'R'. Return the number of possible direction assignments such that the person at index pos sees 
    exactly k people. Since the answer may be large, return it modulo 109 + 7.

    Example 1:
    Input: n = 3, pos = 1, k = 0
    Output: 2
    Explanation:​​​​​​​ Index 0 is to the left of pos = 1, and index 2 is to the right of pos = 1. To see k = 0 people, index 0 must choose 'R' and index 2 must choose 'L', keeping 
    both invisible. The person at index 1 can choose 'L' or 'R' since it does not affect the count. Thus, the answer is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    long long modInverse(long long x) {
        return power(x, MOD - 2);
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n)
            return 0;

        r = min(r, n - r);

        long long numerator = 1;
        long long denominator = 1;

        for (int i = 1; i <= r; i++) {
            numerator = numerator * (n - r + i) % MOD;
            denominator = denominator * i % MOD;
        }

        return numerator * modInverse(denominator) % MOD;
    }

    int countVisiblePeople(int n, int pos, int k) {
        if (k < 0 || k > n - 1)
            return 0;

        return (2LL * nCr(n - 1, k)) % MOD;
    }
};