/*
    Given a string s, return the longest palindromi substring in s.

    Example 1:
    Input: s = "babad"
    Output: "bab"
    Explanation: "aba" is also a valid answer.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2)
            return s;

        int start = 0; 
        int maxLength = 1;

        for (int i = 0; i < n; i++) {
            // Check for odd-length palindromes
            int left = i - 1;
            int right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    maxLength = right - left + 1;
                    start = left;
                }
                left--;
                right++;
            }

            // Check for even-length palindromes
            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    maxLength = right - left + 1;
                    start = left;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxLength);
    }
};