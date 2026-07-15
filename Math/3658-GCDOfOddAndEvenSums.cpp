/*
    You are given an integer n. Your task is to compute the GCD (greatest common divisor) of two values:
    sumOdd: the sum of the smallest n positive odd numbers.
    sumEven: the sum of the smallest n positive even numbers.
    Return the GCD of sumOdd and sumEven.

    Example 1:
    Input: n = 4
    Output: 4
    Explanation: Sum of the first 4 odd numbers sumOdd = 1 + 3 + 5 + 7 = 16 Sum of the first 4 even numbers sumEven = 2 + 4 + 6 + 8 = 20. GCD(sumOdd, sumEven) = GCD(16, 20) = 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // based on this: gcd(a, b) = gcd(b, a mod b)
    // let r = a mod b ==> a = q*b + r 
    // any number that divides both a and b also divides r
    // if d divides both a and b. Since r = a - q*b, and d divides both terms on the right (a and q*b), d must divide r too.
    int gcd(int a, int b) {
        while(b != 0) {
            int rem = a%b;
            a = b;
            b = rem;
        }

        return a;
    }

    int gcdOfOddEvenSums(int n) {
        int odd = 1;
        int sumOdd = 1;
        int even = 2;
        int sumEven = 2;
        int cnt = 1;

        while(cnt != n) {
            odd += 2;
            sumOdd += odd;
            even += 2;
            sumEven += even;
            cnt++;
        }

        return gcd(sumEven, sumOdd);
    }
};