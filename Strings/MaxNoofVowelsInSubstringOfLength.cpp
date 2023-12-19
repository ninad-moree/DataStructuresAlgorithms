/*
    Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
    Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

    Example 1:
    Input: s = "abciiidef", k = 3
    Output: 3
    Explanation: The substring "iii" contains 3 vowel letters.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int ans = 0;
        int curr = 0;

        for (int i = 0; i < k; ++i) {
            if (vowels.count(s[i])) {
                curr++;
            }
        }

        ans = curr;

        for (int i = k; i < s.length(); ++i) {
            if (vowels.count(s[i - k])) {
                curr--;
            }
            if (vowels.count(s[i])) {
                curr++;
            }
            ans = max(ans, curr);
        }

        return ans;
    }
};