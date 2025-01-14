/*
    Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.

    Example 1:
    Input: s = "annabelle", k = 2
    Output: true
    Explanation: You can construct two palindromes using all characters in s. Some possible constructions "anna" + "elble", "anbna" + "elle"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k)
            return false;

        unordered_map<char, int> mp;
        for(auto i : s)
            mp[i]++;

        int cnt = 0;
        for(auto i : mp) {
            if(i.second % 2 == 1)
                cnt++;
        }

        if(cnt > k)
            return false;

        return true;
    }
};