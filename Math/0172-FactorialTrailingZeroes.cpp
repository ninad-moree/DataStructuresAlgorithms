/*
    Given an integer n, return the number of trailing zeroes in n!.
    Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

    Example 1:
    Input: n = 3
    Output: 0
    Explanation: 3! = 6, no trailing zero.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;

        while(n>=5) {
            n = n/5;
            ans += n;
        }

        return ans;
    }
};