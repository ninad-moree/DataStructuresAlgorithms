/*
    You are given a string s and a positive integer k.
    Let vowels and consonants be the number of vowels and consonants in a string.
    A string is beautiful if:
        vowels == consonants.
        (vowels * consonants) % k == 0,
    Return the number of non-empty beautiful substrings in the given string s.

    Example 1:
    Input: s = "baeyh", k = 2
    Output: 2
    Explanation: There are 2 beautiful substrings in the given string.
    You can see that string "aeyh" is beautiful as vowels == consonants and vowels * consonants % k == 0.
    You can see that string "baey" is beautiful as vowels == consonants and vowels * consonants % k == 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            int vowels = 0;
            int conso = 0;

            for (int j = i; j < n; j++) {
                if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                    vowels++;
                else 
                    conso++;

                if (vowels == conso && vowels * conso % k == 0) 
                    res++;
            }
        }

        return res;
    }
};