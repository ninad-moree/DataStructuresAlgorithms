/*
    You are given two non-negative integers n and s. Return the largest integer that has at most n digits and whose sum of digits is s. If no such integer exists, return -1.

    Example 1:
    Input: n = 2, s = 9
    Output: 90
    Explanation: The largest integer with at most 2 digits that has a sum of digits of 9 is 90.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(int n, int s) {
        if (s > 9 * n) 
            return -1;   
        if (s == 0)
            return 0;       

        string num = "";

        for (int i = 0; i < n && s > 0; i++) {
            int digit = min(9, s);   
            num += ('0' + digit);
            s -= digit;
        }

        // if we filled fewer than n digits (s hit 0 early), pad with zeros
        while ((int)num.size() < n) 
            num += '0';
        
        return stoi(num);
    }
};