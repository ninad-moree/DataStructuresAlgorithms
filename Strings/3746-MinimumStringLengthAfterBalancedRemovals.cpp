/*
    You are given a string s consisting only of the characters 'a' and 'b'. You are allowed to repeatedly remove any substring where the number of 'a' characters is equal to 
    the number of 'b' characters. After each removal, the remaining parts of the string are concatenated together without gaps. Return an integer denoting the minimum possible 
    length of the string after performing any number of such operations.

    Example 1:
    Input: s = "aabbab"
    Output: 0
    Explanation: The substring "aabbab" has three 'a' and three 'b'. Since their counts are equal, we can remove the entire string directly. The minimum length is 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int cntA = 0;
        int cntB = 0;

        for(auto i : s) {
            if(i == 'a')
                cntA++;
            else
                cntB++;
        }

        return abs(cntA - cntB);
    }
};