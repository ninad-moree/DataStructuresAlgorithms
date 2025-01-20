/*
    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it
    reads the same forward and backward. Alphanumeric characters include letters and numbers. Given a string s, return true if it is a 
    palindrome, or false otherwise.

    Example 1:
    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void recursive(string& s, int i, int j) {
        if(i >= j)
            return;

        char temp;
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        i++;
        j--;

        recursive(s, i, j);
    }

    bool isPalindrome(string s) {
        string str1 = "";

        for(auto i : s) {
            if (isalnum(i)) 
                str1 += tolower(i);
        }

        string str2 = str1;
        recursive(str2, 0, str2.size()-1);

        return str1 == str2;
    }
};