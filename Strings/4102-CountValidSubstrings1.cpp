/*
    You are given a string s consisting only of the characters 'a', 'b', and 'c'. A string is called valid if it does not contain "abc" as a substring. Return the number of 
    valid substrings in s. Substrings with different starting or ending indices are counted separately.

    Example 1:
    Input: s = "abac"
    Output: 10
    Explanation: The following substrings don't contain "abc"​​​​​​​ as a substring:
    s[0..0] = "a", s[0..1] = "ab", s[0..2] = "aba", s[0..3] = "abac"​​​​​​​, s[1..1] = "b", s[1..2] = "ba", s[1..3] = "bac", s[2..2] = "a", s[2..3] = "ac", s[3..3] = "c"
    Thus, the answer is 10.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countValidSubstrings(string s) {
        long long ans = 0;
        int i = 0;
        int j = 0;

        while(j < s.size()) {
            if(j >= 2 && s[j-2] == 'a' && s[j-1] == 'b' && s[j] == 'c')
                i = j - 1;
            
            ans += (j - i + 1);
            j++;
        }

        return ans;
    }
};