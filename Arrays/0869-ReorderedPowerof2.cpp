/*
    You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
    Return true if and only if we can do this so that the resulting number is a power of two.

    Example 1:
    Input: n = 1
    Output: true
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string str = to_string(n);
        sort(str.begin(), str.end()); 
        
        for (int i = 0; i < 31; i++) {
            int pow2 = 1 << i; // 2^i
            string s = to_string(pow2);
            
            sort(s.begin(), s.end());

            if (s == str) 
                return true;
        }
        
        return false;
    }   
};