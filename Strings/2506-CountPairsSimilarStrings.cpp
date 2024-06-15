/*
    You are given a 0-indexed string array words. Two strings are similar if they consist of the same characters.
    For example, "abca" and "cba" are similar since both consist of characters 'a', 'b', and 'c'.
    However, "abacba" and "bcfd" are not similar since they do not consist of the same characters.
    Return the number of pairs (i, j) such that 0 <= i < j <= word.length - 1 and the two strings words[i] and words[j] are similar.

    Example 1:
    Input: words = ["aba","aabb","abcd","bac","aabc"]
    Output: 2
    Explanation: There are 2 pairs that satisfy the conditions:
    - i = 0 and j = 1 : both words[0] and words[1] only consist of characters 'a' and 'b'. 
    - i = 3 and j = 4 : both words[3] and words[4] only consist of characters 'a', 'b', and 'c'. 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ans = 0;
        
        for (int i = 0; i < words.size(); i++) {
            vector<bool> f1(26, false);
            for (char c : words[i]) 
                f1[c - 'a'] = true;
            
            for (int j = i + 1; j < words.size(); j++) {
                vector<bool> f2(26, false);
                for (char c : words[j]) 
                    f2[c - 'a'] = true;
                
                bool same = true;
                for (int k = 0; k < 26; k++) {
                    if (f1[k] != f2[k]) {
                        same = false;
                        break;
                    }
                }
                
                if (same) 
                    ans++;
            }
        }
        
        return ans;
    }
};
