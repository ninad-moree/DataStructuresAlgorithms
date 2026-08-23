/*
    You are given a string s consisting of lowercase English letters. Construct a binary string by replacing each character in s with the 8-bit binary representation of its 
    ASCII value, including leading zeros, while preserving the original order of the characters. Return true if the resulting binary string is a palindrome else return false.

    Example 1:
    Input: s = "ff"
    Output: true
    Explanation: The ASCII value of f is 102, whose 8-bit binary representation is 01100110. Thus, the binary string is 0110011001100110. Since this binary string is a 
    palindrome, the output is true.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int i, int j, string s) {
        while(i < j) {
            if(s[i] != s[j])
                return false;
            
            i++;
            j--;
        }

        return true;
    }

    string convertToBinary(int n) {
        string s = "";

        while(n) {
            int rem = n % 2;
            n = n/2;

            s += to_string(rem);
        }

        reverse(s.begin(), s.end());

        while (s.size() < 8) 
            s = '0' + s;

        return s;
    }

    bool isPalindromic(string s) {
        string res = "";

        for(int i=0; i<s.size(); i++) {
            int ascii = (int)s[i];
            res += convertToBinary(ascii);
        }

        return isPalindrome(0, res.size() - 1, res);
    }
};