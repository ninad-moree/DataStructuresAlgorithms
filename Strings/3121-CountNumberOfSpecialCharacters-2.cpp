/*
    You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase 
    occurrence of c appears before the first uppercase occurrence of c. Return the number of special letters in word.
    
    Example 1:
    Input: word = "aaAbcBC"
    Output: 3
    Explanation:
    The special characters are 'a', 'b', and 'c'.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt = 0;

        vector<int> lower(150, -1);
        vector<int> upper(150, -1);

        for(int i=0; i<word.size(); i++) {
            if(word[i] >= 65 && word[i] <= 90) {
                if(lower[word[i]] == -1)
                    lower[word[i]] = i;
            } else
                upper[word[i]] = i;
        }

        for(int i=0; i<lower.size(); i++) {
            if(lower[i] == -1 || upper[i+32] == -1)
                continue;
            if(upper[i+32] < lower[i])
                cnt++;
        }

        return cnt;
    }
};