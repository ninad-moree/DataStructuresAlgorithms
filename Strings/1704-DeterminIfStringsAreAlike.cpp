/*
    You are given a string s of even length. Split this string into two halves of equal lengths, and let a 
    be the first half and b be the second half.
    Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). 
    Notice that s contains uppercase and lowercase letters.
    Return true if a and b are alike. Otherwise, return false.

    Example 1:
    Input: s = "book"
    Output: true
    Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();

        int cnta = 0;
        int cntb = 0;

        int i=0;
        int j=n/2;

        while(j<n) {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
                cnta++;
            
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u' || s[j]=='A' || s[j]=='E' || s[j]=='I' || s[j]=='O' || s[j]=='U')
                cntb++;
                
            i++;
            j++;
        }

        return cnta == cntb;
    }
};