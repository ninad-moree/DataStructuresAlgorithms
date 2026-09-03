/*
    You are given a string s of length n consisting of lowercase English letters. Return the smallest index i such that s[i] == s[n - i - 1]. If no such index exists, return -1.

    Example 1:
    Input: s = "abcacbd"
    Output: 1
    Explanation: At index i = 1, s[1] and s[5] are both 'b'. No smaller index satisfies the condition, so the answer is 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMatchingIndex(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i <= j) {
            if(s[i] == s[j])
                return i;
            
            i++;
            j--;
        }

        return -1;
    }
};