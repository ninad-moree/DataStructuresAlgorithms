/*
    You are given two binary strings s and t​​​​​​​, each of length n. You may rearrange the characters of t in any order, but s must remain unchanged. Return a binary string of 
    length n representing the maximum integer value obtainable by taking the bitwise XOR of s and rearranged t.

    Example 1:
    Input: s = "101", t = "011"
    Output: "110"
    Explanation: One optimal rearrangement of t is "011". The bitwise XOR of s and rearranged t is "101" XOR "011" = "110", which is the maximum possible.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumXor(string s, string t) {
        int n = t.size();
        int cnt0 = 0;

        for (char ch : t) {
            if (ch == '0')
                cnt0++;
        }

        int cnt1 = n - cnt0;

        string ans;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                // 0 XOR 1 = 1
                if (cnt1 > 0) {
                    ans += '1';
                    cnt1--;
                } else {
                    ans += '0';
                    cnt0--;
                }
            }
            else {
                // 1 XOR 0 = 1
                if (cnt0 > 0) {
                    ans += '1';
                    cnt0--;
                } else {
                    ans += '0';
                    cnt1--;
                }
            }
        }

        return ans;
    }
};