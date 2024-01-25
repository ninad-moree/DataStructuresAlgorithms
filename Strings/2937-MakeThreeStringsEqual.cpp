/*
    You are given three strings s1, s2, and s3. You have to perform the following operation on these three strings as
     many times as you want.
    In one operation you can choose one of these three strings such that its length is at least 2 and delete the rightmost 
    character of it.
    Return the minimum number of operations you need to perform to make the three strings equal if there is a way to make 
    them equal, otherwise, return -1.

    Example 1:
    Input: s1 = "abc", s2 = "abb", s3 = "ab"
    Output: 2
    Explanation: Performing operations on s1 and s2 once will lead to three equal strings.
    It can be shown that there is no way to make them equal with less than two operations.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        string pre = "";

        int i=0;
        int j=0;
        int k=0;

        while(i<s1.size() && j<s2.size() && k<s3.size()) {
            if(s1[i]==s2[j] && s2[j]==s3[k]) {
                pre += s1[i];
                i++;
                j++;
                k++;
            }
            else
                break;
        }

        int res = pre.size();

        int ans = -1;

        if(res >0)
            ans = (s1.size()-res) + (s2.size()-res) + (s3.size()-res);

        return ans;
    }
};