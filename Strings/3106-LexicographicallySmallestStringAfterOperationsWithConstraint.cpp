/*
    You are given a string s and an integer k.
    Define a function distance(s1, s2) between two strings s1 and s2 of the same length n as:
    The sum of the minimum distance between s1[i] and s2[i] when the characters from 'a' to 'z' are placed in a cyclic order, 
    for all i in the range [0, n - 1].
    For example, distance("ab", "cd") == 4, and distance("a", "z") == 1.
    You can change any letter of s to any other lowercase English letter, any number of times.
    Return a string denoting the 
    lexicographically smallest
    string t you can get after some changes, such that distance(s, t) <= k.

    Example 1:
    Input: s = "zbbz", k = 3
    Output: "aaaz"
    Explanation:
    Change s to "aaaz". The distance between "zbbz" and "aaaz" is equal to k = 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getSmallestString(string s, int k) {
        for(int i=0; i<s.size(); i++) {
            int left = s[i] - 'a';
            int right = 'z' - s[i] + 1;

            int mini = min(left, right);

            if(k >= mini) {
                k-= mini;
                s[i] = 'a';
            } else {
                s[i] = s[i] - k;
                k = 0;
            }
        }

        return s;
    }
};