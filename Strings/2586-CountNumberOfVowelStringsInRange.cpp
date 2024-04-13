/*
    You are given a 0-indexed array of string words and two integers left and right.
    A string is called a vowel string if it starts with a vowel character and ends with a vowel character where vowel characters
     are 'a', 'e', 'i', 'o', and 'u'.
    Return the number of vowel strings words[i] where i belongs to the inclusive range [left, right].

    Example 1:
    Input: words = ["are","amy","u"], left = 0, right = 2
    Output: 2
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;

        for(int i=left; i<=right; i++) {
            string str = words[i];
            char s = str[0];
            char e = str[str.size()-1];

            if((s=='a' || s=='e' || s=='i' || s=='o' || s=='u') && (e=='a' || e=='e' || e=='i' || e=='o' || e=='u')) 
                ans++;
        }

        return ans;
    }
};