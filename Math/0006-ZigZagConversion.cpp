/*
    The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
    (you may want to display this pattern in a fixed font for better legibility)
    P   A   H   N
    A P L S I I G
    Y   I   R
    And then read line by line: "PAHNAPLSIIGYIR"
    
    Example 1:
    Input: s = "PAYPALISHIRING", numRows = 3
    Output: "PAHNAPLSIIGYIR"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) 
            return s;

        string ans = "";
        
        for(int i=0;i<numRows;i++) {
            int inc = 2*(numRows-1);
            for(int j=i; j<s.size(); j = j+inc) {
                ans += s[j];
                if(i>0 && i<numRows-1 &&  j+inc-2*i < s.size())
                    ans+=s[j+inc-2*i];
            }
        }
        return ans;
    }
};