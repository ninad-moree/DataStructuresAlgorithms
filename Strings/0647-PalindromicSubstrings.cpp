/*
    Given a string s, return the number of palindromic substrings in it.
    A string is a palindrome when it reads the same backward as forward.
    A substring is a contiguous sequence of characters within the string.

    Example 1:
    Input: s = "abc"
    Output: 3
    Explanation: Three palindromic strings: "a", "b", "c".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string s2 = s; 
        reverse(s2.begin(), s2.end());
        if(s == s2)
            return true;
        else 
            return false;
    }
    
    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0;i<s.size();i++) {
            string str = "";
            for(int j=i;j<s.size();j++) {
                str += s[j];
                if(isPalindrome(str))
                    ans++;
            }
        }
        return ans;
    }
};