/*
    You are given a palindromic string s. Return the lexicographically smallest palindromic permutation of s.

    Example 1:
    Input: s = "z"
    Output: "z"
    Explanation: A string of only one character is already the lexicographically smallest palindrome.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int uniqueChars = n / 2;

        sort(s.begin(), s.begin() + uniqueChars);

        for(int i=0; i<n/2; i++) 
            s[n - 1 - i] = s[i];
        
        return s;
    }
};