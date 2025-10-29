/*
    You are given a positive number n. Return the smallest number x greater than or equal to n, such that the binary representation of x contains only set bits

    Example 1:
    Input: n = 5
    Output: 7
    Explanation: The binary representation of 7 is "111".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        int ans = 1;
        while(ans < n)
            ans = ans*2 + 1;
        return ans;
    }
};