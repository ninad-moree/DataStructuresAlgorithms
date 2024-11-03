/*
    Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s. A shift on s consists of moving the 
    leftmost character of s to the rightmost position. For example, if s = "abcde", then it will be "bcdea" after one shift.

    Example 1:
    Input: s = "abcde", goal = "cdeab"
    Output: true
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string s) {
        string ans="";
        for(int i=1;i<s.size();i++) 
            ans+=s[i];
        ans+=s[0];
        
        return ans;
    }

    bool rotateString(string s, string goal) {
        bool ans = false;
        string rots=s;

        for(int i=0;i<s.size();i++){
            rots = solve(rots);
            if(rots==goal) {
                ans=true;
                break;
            }
        }

        return ans;
    }
};