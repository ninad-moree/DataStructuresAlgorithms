/*
    Given a string s, calculate its reverse degree. The reverse degree is calculated as follows: For each character, multiply its position in the reversed alphabet 
    ('a' = 26, 'b' = 25, ..., 'z' = 1) with its position in the string (1-indexed). Sum these products for all characters in the string. Return the reverse degree of s.

    Example 1:
    Input: s = "abc"
    Output: 148
    Explanation: The reversed degree is 26 + 50 + 72 = 148.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for(int i=0; i<s.size(); i++) {
            int idx = i + 1;
            int n = 26 - (s[i] - 'a');
            
            ans += (idx * n);
        }

        return ans;
    }
};