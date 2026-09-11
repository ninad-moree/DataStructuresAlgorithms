/*
    You are given a string s and an integer k. Reverse the first k characters of s and return the resulting string.

    Example 1:
    Input: s = "abcd", k = 2
    Output: "bacd"
    Explanation:​​​​​​​ The first k = 2 characters "ab" are reversed to "ba". The final resulting string is "bacd".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reversePrefix(string s, int k) {
        int i = 0;
        int j = k-1;

        while(i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }

        return s;
    }
};