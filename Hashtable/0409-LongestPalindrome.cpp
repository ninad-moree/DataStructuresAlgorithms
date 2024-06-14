/*
    Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with 
    those letters. Letters are case sensitive, for example, "Aa" is not considered a palindrome.

    Example 1:
    Input: s = "abccccdd"
    Output: 7
    Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for (char c : s) 
            mp[c]++;

        int ans = 0;
        bool oddFound = false;

        for (auto& i : mp) {
            if (i.second % 2 == 0)
                ans += i.second;
            else {
                ans += i.second - 1;
                oddFound = true;
            }
        }

        if (oddFound) 
            ans += 1;

        return ans;
    }
};
