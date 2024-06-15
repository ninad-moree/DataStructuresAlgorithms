/*
    You are given two integers n and k. Initially, you start with an array a of n integers where a[i] = 1 for all 0 <= i <= n - 1. After each 
    second, you simultaneously update each element to be the sum of all its preceding elements plus the element itself. For example, after one 
    second, a[0] remains the same, a[1] becomes a[0] + a[1], a[2] becomes a[0] + a[1] + a[2], and so on. Return the value of a[n - 1] after k 
    seconds. Since the answer may be very large, return it modulo 109 + 7.

    Example 1:
    Input: n = 4, k = 5
    Output: 56
    Explanation:
    Second	State After
    0	[1,1,1,1]
    1	[1,2,3,4]
    2	[1,3,6,10]
    3	[1,4,10,20]
    4	[1,5,15,35]
    5	[1,6,21,56]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        long long MOD = 1e9 + 7;
        
        vector<int> a(n, 1);
        vector<int> prefix(n);

        prefix[0] = a[0];
        for(int i=1; i<n; i++) 
            prefix[i] = prefix[i-1] + a[i];
        
        int j = 1;
        while(j < k) {
            a = prefix;
            for(int i=1; i<n; i++) 
                prefix[i] = (prefix[i-1] + a[i]) % MOD;
            j++;
        }

        return prefix[n-1] % MOD;
    }
};