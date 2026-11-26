/*
    You are given a string s consisting only of the characters 'a', 'b', and 'c'. A string is called valid if it does not contain "abc" as a subsequence.
    Return the number of valid substrings in s. Substrings with different starting or ending indices are counted separately.

    Example 1:
    Input: s = "abac"
    Output: 9
    Explanation: The following substrings don't contain "abc"​​​​​​​ as a subsequence:
    s[0..0] = "a", s[0..1] = "ab", s[0..2] = "aba", s[1..1] = "b", s[1..2] = "ba", s[1..3] = "bac", s[2..2] = "a", s[2..3] = "ac", s[3..3] = "c"
    Thus, the answer is 9.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countValidSubstrings(string s) {
        long long ans = 0;
        
        int a = -1;
        int b = -1;
        int c = -1;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == 'a')
                a = i;
            else if(s[i] == 'b')
                b = a;
            else
                c = b;

            ans += (i - c);
        }

        return ans;
    }
};