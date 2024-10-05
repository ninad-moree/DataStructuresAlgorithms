/*
    Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise. In other words, return true if one of s1's 
    permutations is the substring of s2.

    Example 1:
    Input: s1 = "ab", s2 = "eidbaooo"
    Output: true
    Explanation: s2 contains one permutation of s1 ("ba").
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size();
    
        if (l1 > s2.size()) 
            return false; 
        
        sort(s1.begin(), s1.end());

        for (int i = 0; i <= s2.size() - l1; i++) {
            string temp = s2.substr(i, l1); 
            sort(temp.begin(),temp.end());

            if(temp == s1) 
                return true;
        }
        
        return false;
    }
};