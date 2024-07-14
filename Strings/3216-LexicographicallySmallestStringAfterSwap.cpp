/*
    Given a string s containing only digits, return the  lexicographically smallest string that can be obtained after swapping adjacent 
    digits in s with the same parity at most once. Digits have the same parity if both are odd or both are even. For example, 5 and 9, as
    well as 2 and 4, have the same parity, while 6 and 9 do not.

    Example 1:
    Input: s = "45320"
    Output: "43520"
    Explanation:
    s[1] == '5' and s[2] == '3' both have the same parity, and swapping them results in the lexicographically smallest string.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getSmallestString(string s) {
        for(int i=0; i<s.size()-1; i++) {
            string s1 = "";
            string s2 = "";
            s1 += s[i];
            s2 += s[i+1];
            int n1 = stoi(s1);
            int n2 = stoi(s2);

            if(n1%2 == n2%2) {
                if(n1 > n2) {
                    s[i] = s2[0];
                    s[i+1] = s1[0];
                    break;
                }
            }
        }

        return s;
    }
};