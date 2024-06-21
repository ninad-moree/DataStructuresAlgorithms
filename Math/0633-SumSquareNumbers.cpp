/*
    Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

    Example 1:
    Input: c = 5
    Output: true
    Explanation: 1 * 1 + 2 * 2 = 5
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(long long n) {
        long long root = static_cast<long long>(sqrt(n));
        return root * root == n;
    }

    bool judgeSquareSum(int c) {
        for (long long a = 0; a * a <= c; ++a) {
            long long b = c - a * a;
            if (isPerfectSquare(b)) 
                return true;
        }
        return false;
    }
};