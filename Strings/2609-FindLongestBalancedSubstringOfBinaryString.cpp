/*
    You are given a binary string s consisting only of zeroes and ones.
    A substring of s is considered balanced if all zeroes are before ones and the number of zeroes is equal to the number of ones inside the substring. 
    Notice that the empty substring is considered a balanced substring. Return the length of the longest balanced substring of s.

    Example 1:
    Input: s = "01000111"
    Output: 6
    Explanation: The longest balanced substring is "000111", which has length 6.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int i = 0;
        int ans = 0;

        while(i < s.size()) {
            int cnt1 = 0;
            int cnt0 = 0;

            while(i<s.size() && s[i] == '0') {
                if(s[i] == '0') {
                    cnt0++;
                    i++;
                } else
                    break;
            }

            while(i<s.size() && s[i] == '1') {
                if(s[i]=='1' && cnt0!=0) {
                    cnt1++;
                    i++;
                } else {
                    i++;
                    break;
                }
            }

            if(cnt0 == cnt1)
                ans = max(ans, cnt0+cnt1);
            else
                ans = max(ans, 2*min(cnt0, cnt1));
        }

        return ans;
    }
};