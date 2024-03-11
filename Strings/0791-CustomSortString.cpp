/*
    You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
    Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before 
    a character y in order, then x should occur before y in the permuted string.
    Return any permutation of s that satisfies this property.

    Example 1:
    Input:  order = "cba", s = "abcd" 
    Output:  "cbad" 
    Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".
    Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";

        vector<int> count(26, 0);
        for (char c : s) 
            count[c - 'a']++;

        for (char c : order) {
            while (count[c - 'a']-- > 0) 
                ans += c;
        }

        for (int i = 0; i < 26; i++) {
            while (count[i]-- > 0) 
                ans += (i + 'a');
        }

        return ans;
    }
};