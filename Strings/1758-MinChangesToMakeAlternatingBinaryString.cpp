/*
    You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any 
    '0' to '1' or vice versa.
    The string is called alternating if no two adjacent characters are equal. For example, the string "010" is 
    alternating, while the string "0100" is not.
    Return the minimum number of operations needed to make s alternating.

    Example 1:
    Input: s = "0100"
    Output: 1
    Explanation: If you change the last character to '1', s will be "0101", which is alternating.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int szero = 0;
        int sone = 0;

        //start with zero
        for(int i=0;i<s.size();i++) {
            if(i%2==0 && s[i]!='0')
                szero++;
            if(i%2==1 && s[i]!='1')
                szero++;
        }

        //start with one
        for(int i=0;i<s.size();i++) {
            if(i%2==0 && s[i]!='1')
                sone++;
            if(i%2==1 && s[i]!='0')
                sone++;
        }

        int ans = min(sone, szero);

        return ans;
    }
};