/*
    You are given a positive integer n. Let digitSum be the sum of the digits of n, and let squareSum be the sum of the squares of the digits of n.
    An integer is called good if squareSum - digitSum >= 50. Return true if n is good. Otherwise, return false.

    Example 1:
    Input: n = 1000
    Output: false
    Explanation: The digits of 1000 are 1, 0, 0, and 0. The digitSum is 1 + 0 + 0 + 0 = 1. The squareSum is 12 + 02 + 02 + 02 = 1.
    The squareSum - digitSum is 1 - 1 = 0. As 0 is not greater than or equal to 50, the output is false.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitSum = 0;
        int squareSum = 0;

        while(n) {
            int d = n % 10;
            n = n/10;

            digitSum += d;
            squareSum += (d*d);
        }

        return squareSum - digitSum >= 50;
    }
};