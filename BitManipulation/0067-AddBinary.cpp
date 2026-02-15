/*
    Given two binary strings a and b, return their sum as a binary string.

    Example 1:
    Input: a = "11", b = "1"
    Output: "100"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";

        int n = a.size();
        int m = b.size();

        int i = n-1;
        int j = m-1;
        int carry = 0;

        while(i >=0 && j >= 0) {
            char s1 = a[i];
            char s2 = b[j];

            if(s1 == '1' && s2 == '1') {
                if(carry == 1) {
                    ans += '1';
                    carry = 1;
                } else {
                    ans += '0';
                    carry = 1;
                }
            } else if(s1 == '1' || s2 == '1') {
                if(carry == 1) {
                    ans += '0';
                    carry = 1;
                } else {
                    ans += '1';
                    carry = 0;
                }
            } else if(s1 == '0' && s2 == '0') {
                if(carry == 1) {
                    ans += '1';
                    carry = 0;
                } else {
                    ans += '0';
                    carry = 0;
                }
            }

            i--;
            j--;
        }

        while(i >= 0) {
            if(a[i] == '1') {
                if(carry) {
                    ans += '0';
                    carry = 1;
                } else {
                    ans += '1';
                    carry = 0;
                }
            } else {
                if(carry) {
                    ans += '1';
                    carry = 0;
                } else {
                    ans += '0';
                    carry = 0;
                }
            }
            i--;
        }

        while(j >= 0) {
            if(b[j] == '1') {
                if(carry) {
                    ans += '0';
                    carry = 1;
                } else {
                    ans += '1';
                    carry = 0;
                }
            } else {
                if(carry) {
                    ans += '1';
                    carry = 0;
                } else {
                    ans += '0';
                    carry = 0;
                }
            }
            j--;
        }

        if(carry)
            ans += '1';

        reverse(ans.begin(), ans.end());
        return ans;
    }
};