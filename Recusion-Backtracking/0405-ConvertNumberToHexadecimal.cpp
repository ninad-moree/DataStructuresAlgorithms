/*
    Given an integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.
    All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the 
    zero itself.

    Example 1:
    Input: num = 26
    Output: "1a"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(unsigned int n, string ans) {
        char arr[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        if(n/16 == 0)
            return arr[n%16] + ans;
        return arr[n%16] + solve(n/16, ans);
    }

    string toHex(int num) {
        unsigned int n = num;
        string ans = solve(n, "");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};