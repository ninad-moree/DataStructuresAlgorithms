/*
    You are given two strings s1 and s2, both of length 4, consisting of lowercase English letters.
    You can apply the following operation on any of the two strings any number of times:
    Choose any two indices i and j such that j - i = 2, then swap the two characters at those indices in the string.
    Return true if you can make the strings s1 and s2 equal, and false otherwise.

    Example 1:
    Input: s1 = "abcd", s2 = "cdab"
    Output: true
    Explanation: We can do the following operations on s1:
    - Choose the indices i = 0, j = 2. The resulting string is s1 = "cbad".
    - Choose the indices i = 1, j = 3. The resulting string is s1 = "cdab" = s2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1 == s2)
            return true;
        
        swap(s1[0], s1[2]);
        if(s1 == s2)
            return true;
        swap(s1[0], s1[2]);

        swap(s1[1], s1[3]);
        if(s1 == s2)
            return true;
        swap(s1[1], s1[3]);

        swap(s1[0], s1[2]);
        swap(s1[1], s1[3]);
        if(s1 == s2)
            return true;
        
        return false;
    }
};