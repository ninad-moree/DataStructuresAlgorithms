/*
    You are given two strings s and t such that every character occurs at most once in s and t is a permutation of s. The permutation difference 
    between s and t is defined as the sum of the absolute difference between the index of the occurrence of each character in s and the index of 
    the occurrence of the same character in t. Return the permutation difference between s and t.

    Example 1:
    Input: s = "abc", t = "bac"
    Output: 2
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPermutationDifference(string s, string t) {
       vector<pair<int, int>> freq(26, make_pair(-1, -1));
        
        for(int i=0; i<s.size(); i++) {
            freq[s[i] - 'a'].first = i;
            freq[t[i] - 'a'].second = i;
        }
        
        int sum = 0;
        for(int i=0; i<freq.size(); i++) {
            int f=-1, s=-1;
            
            if(freq[i].first != -1) {
                f = freq[i].first;
                s = freq[i].second;
            }
            
            if(f!=-1 && s!=-1) {
                sum += abs(f-s);
            }
        }
        
        return sum;
        
    }
};