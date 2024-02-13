/*
    Given an array of strings words, return the first palindromic string in the array. 
    If there is no such string, return an empty string "".
    A string is palindromic if it reads the same forward and backward.

    Example 1:
    Input: words = ["abc","car","ada","racecar","cool"]
    Output: "ada"
    Explanation: The first string that is palindromic is "ada".
    Note that "racecar" is also palindromic, but it is not the first.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++) {
            string str = words[i];
            reverse(str.begin(), str.end());
            if(words[i] == str)
                return words[i];
        }
        return "";
    }
};