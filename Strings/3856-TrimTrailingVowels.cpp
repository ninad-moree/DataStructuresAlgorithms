/*
    You are given a string s that consists of lowercase English letters. Return the string obtained by removing all trailing vowels from s. The vowels consist of the characters
    'a', 'e', 'i', 'o', and 'u'.

    Example 1:
    Input: s = "idea"
    Output: "id"
    Explanation: Removing "idea", we obtain the string "id".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string trimTrailingVowels(string s) {
        string ans = s;
        
        for(int i=s.size()-1; i>=0; i--) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                ans.pop_back();
            else
                break;
        }

        return ans;
    }
};