/*
    Given two strings text and pattern, find the first index where pattern exactly matches with any substring of text. 
    Return -1 if pattern doesn't exist as a substring in text.

    Example 1:
    Input:
    text = gffgfg
    pattern = gfg
    Output: 3
    Explanation:  Considering 0-based indexing, substring of text from 3rd to last index is gfg.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMatching(string text, string pat) {
        int i=0;
        int j=0;
        
        int n = text.size();
        int m = pat.size();
        
        if(n < m)
            return -1;
        
        int idx = -1;
        int len = 0;
        
        while(i<n) {
            if(text[i] == pat[j]) {
                if(len == 0)
                    idx = i;
                i++;
                j++;
                len++;
                
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