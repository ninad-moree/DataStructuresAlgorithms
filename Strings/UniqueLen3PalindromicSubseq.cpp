/*
    Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
    Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.
    A palindrome is a string that reads the same forwards and backwards.
    A subsequence of a string is a new string generated from the original string with some characters (can be none)
     deleted without changing the relative order of the remaining characters.
    For example, "ace" is a subsequence of "abcde".

    Input: s = "aabca"
    Output: 3
    Explanation: The 3 palindromic subsequences of length 3 are:
                    - "aba" (subsequence of "aabca")
                    - "aaa" (subsequence of "aabca")
                    - "aca" (subsequence of "aabca")
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<vector<int>>left(n,vector<int>(26,0));
        vector<vector<int>>right(n,vector<int>(26,0));

        
        for(int i=0;i<n;i++){
            left[i][s[i]-'a']++;
            if(i!=n-1) left[i+1]=left[i];
        }
        for(int i=n-1;i>=0;i--){
            right[i][s[i]-'a']++;
            if(i!=0) right[i-1]=right[i];
        }

        unordered_set<string>st;
        for(int i=1;i<n-1;i++){
            for(int j=0;j<26;j++){
                if(left[i-1][j]>0 && right[i+1][j]>0){
                    string temp;
                    temp+=(j+'a');
                    temp+=s[i];
                    temp+=(j+'a');
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }
};