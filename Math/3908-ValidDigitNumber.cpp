/*
    You are given an integer n and a digit x. A number is considered valid if: It contains at least one occurrence of digit x, and It does not start with digit x.
    Return true if n is valid, otherwise return false.

    Example 1:
    Input: n = 101, x = 0
    Output: true
    Explanation: The number contains digit 0 at index 1. It does not start with 0, so it satisfies both conditions. Thus, the answer is true​​​​​​​.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validDigit(int n, int x) {
        string res = to_string(n);
        int d0 = res[0] - '0';

        if(d0 == x)
            return false;

        bool isX = false;
        while(n) {
            int d = n % 10;
            if(d == x) {
                isX = true;
                break;
            }

            n = n / 10;
        }

        return isX;
    }
};