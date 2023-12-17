/*
    You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, 
    starting with word1. If a string is longer than the other, append the additional letters onto the end 
    of the merged string.
    Return the merged string.

    Example 1:

    Input: word1 = "abc", word2 = "pqr"
    Output: "apbqcr"
    Explanation: The merged string will be merged as so:
    word1:  a   b   c
    word2:    p   q   r
    merged: a p b q c r
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n = word1.size();
        int m = word2.size();
        int i=0;
        int j=0;
        while(i<n && j<m) {
            ans += word1[i];
            i++;
            ans+=word2[j];
            j++;
        }
        while(i<n) {
            ans += word1[i];
            i++;
        }
        while(j<m) {
            ans += word2[j];
            j++;
        }
        return ans;
    }
};