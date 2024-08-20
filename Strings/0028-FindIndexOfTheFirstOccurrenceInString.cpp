/*
    Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

    Input: haystack = "sadbutsad", needle = "sad"
    Output: 0
    Explanation: "sad" occurs at index 0 and 6. The first occurrence is at index 0, so we return 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if(m > n)
            return -1;
        
        int idx = -1;
        int len = 0;
        int i = 0;
        int j = 0;
        
        while(i<n) {
            if(haystack[i] == needle[j]) {
                if(len == 0)
                    idx = i;
                len++;
                i++;
                j++;

                if(len == m)
                    return idx;
            } else {
                if(len > 0)
                    i = idx+1;
                else
                    i++;
                j = 0;
                len = 0;
            }
        }

        return -1;
    }
};