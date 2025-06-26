/*
    You are given a binary string s and a positive integer k. Return the length of the longest subsequence of s that makes up a binary number less 
    than or equal to k.

    Note:
    The subsequence can contain leading zeroes. The empty string is considered to be equal to 0.
    A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining 
    characters.
    

    Example 1:
    Input: s = "1001010", k = 5
    Output: 5
    Explanation: The longest subsequence of s that makes up a binary number less than or equal to 5 is "00010", as this number is equal to 2 in 
    decimal. Note that "00100" and "00101" are also possible, which are equal to 4 and 5 in decimal, respectively.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int zero = 0;
        for(auto i : s) {
            if(i == '0')
                zero++;
        }

        int num = 0;
        int base = 1;
        int cnt = 0;

        for(int i=s.size()-1; i>=0; i--) {
            if(num + base > k)
                break;
            
            if(s[i] == '1')
                num += base;
            else
                zero--;

            base *= 2;
            cnt++;
        }

        return cnt + zero;
    }
};