/*
    You are given an integer n. The Fibonacci sequence starts with 0 and 1, and each subsequent number is the sum of the previous two numbers. Its first few terms are 0, 1, 1, 
    2, 3, 5, 8, 13, .... Return true if n can be expressed as the sum of three consecutive terms in the Fibonacci sequence, and false otherwise.

    Example 1:
    Input: n = 16
    Output: true
    Explanation: The three consecutive terms 3, 5, and 8 have a sum of 3 + 5 + 8 = 16.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool threeFibonacciSum(int n) {
        long long a = 0;
        long long b = 1;
        long long c = 1;

        while(a + b + c < n) {
            a = b;
            b = c;
            c = a + b;
        }

        return (a + b + c) == n;
    }
};