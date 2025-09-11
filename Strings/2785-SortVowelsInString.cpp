/*
    Given a 0-indexed string s, permute s to get a new string t such that:
    All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, 
    then t[i] = s[i].
    The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length
     such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
    Return the resulting string.
    The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.

    Example 1:
    Input: s = "lEetcOde"
    Output: "lEOtcede"
    Explanation: 'E', 'O', and 'e' are the vowels in s; 'l', 't', 'c', and 'd' are all consonants. The vowels are sorted according to their ASCII
    values, and the consonants remain in the same places.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        string ans = s;
        vector<char> vowels;

        for(int i=0; i<s.size(); i++) {
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') 
                vowels.push_back(s[i]);
        }

        sort(vowels.begin(), vowels.end());

        int j = 0;
        for(int i=0; i<ans.size(); i++) {
            if(ans[i]=='A' || ans[i]=='E' || ans[i]=='I' || ans[i]=='O' || ans[i]=='U' || ans[i]=='a' || ans[i]=='e' || ans[i]=='i' || ans[i]=='o' || ans[i]=='u') {
                ans[i] = vowels[j];
                j++;
            }
        }

        return ans;
    }
};