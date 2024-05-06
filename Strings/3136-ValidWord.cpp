/*
    A word is considered valid if:
    It contains a minimum of 3 characters.
    It consists of the digits 0-9, and the uppercase and lowercase English letters. (Not necessary to have all of them.)
    It includes at least one vowel.
    It includes at least one consonant.
    You are given a string word.
    Return true if word is valid, otherwise, return false.

    Example 1:
    Input: word = "234Adas"
    Output: true
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        int n = word.size();

        if(n < 3)
            return false;
        
        int vowels = 0;
        int cons = 0;

        for(auto i : word) {
            if(isalpha(i)) {
                if(i=='a' || i=='e' || i=='i' || i=='o' || i=='u' || i=='A' || i=='E' || i=='I' || i=='O' || i=='U') 
                    vowels++;
                else
                    cons++;
            }
            if(!(isalpha(i) || isdigit(i)))
                return false;
        }

        if(vowels > 0 && cons > 0)
            return true;
        return false;
    }
};