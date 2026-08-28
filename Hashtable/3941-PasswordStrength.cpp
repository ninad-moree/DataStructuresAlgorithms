/*
    You are given a string password. The strength of the password is calculated based on the following rules:
    1 point for each distinct lowercase letter ('a' to 'z'). 2 points for each distinct uppercase letter ('A' to 'Z').
    3 points for each distinct digit ('0' to '9'). 5 points for each distinct special character from the set "!@#$".
    Each character contributes at most once, even if it appears multiple times. Return an integer denoting the strength of the password.

    Example 1:
    Input: password = "aA1!"
    Output: 11
    Explanation: The distinct characters are 'a', 'A', '1' and '!'. Thus, the strength = 1 + 2 + 3 + 5 = 11.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int passwordStrength(string password) {
        unordered_map<char, int> mp;
        int ans = 0;

        for(auto i : password) {
            char ch = i;

            if(mp.find(ch) == mp.end()) {
                mp[ch]++;

                if(ch >= 'a' && ch <= 'z')
                    ans += 1;
                else if(ch >= 'A' && ch <= 'Z')
                    ans += 2;
                else if(ch >= '0' && ch <= '9')
                    ans += 3;
                else
                    ans += 5;
            }
        }

        return ans;
    }
};