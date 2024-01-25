/*
    There are n balls on a table, each ball has a color black or white.
    You are given a 0-indexed binary string s of length n, where 1 and 0 represent 
    black and white balls, respectively.
    In each step, you can choose two adjacent balls and swap them.
    Return the minimum number of steps to group all the black balls to the right and 
    all the white balls to the left.

    Example 1:
    Input: s = "101"
    Output: 1
    Explanation: We can group all the black balls to the right in the following way:
    - Swap s[0] and s[1], s = "011".
    Initially, 1s are not grouped together, requiring at least 1 step to group them to the right.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        string expected = s;
        sort(expected.begin(),expected.end()); 
        
        long long ans = 0;
        int n = s.size();
        
        int i=0, j=n-1;
        while(i<=j){
            while(j>=i && s[j]==expected[j]) 
                j--;
            
            if(s[i] != expected[i]){
                swap(s[i],s[j]);
                ans += (j-i);
            }
            else
                i++;
        }
        
        return ans;
    }
};