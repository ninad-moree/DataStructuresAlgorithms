/*
    You are given a positive integer n. Determine whether n is divisible by the sum of the following two values:
    The digit sum of n (the sum of its digits). The digit product of n (the product of its digits). Return true if n is divisible by this sum; otherwise, return false.

    Example 1:
    Input: n = 99
    Output: true
    Explanation: Since 99 is divisible by the sum (9 + 9 = 18) plus product (9 * 9 = 81) of its digits (total 99), the output is true.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        int num = n;

        while(n > 0) {
            int digit = n % 10;
            n = n /10;

            sum += digit;
            prod *= digit;
        }

        int total = sum + prod;

        return num % total == 0;
    }
};