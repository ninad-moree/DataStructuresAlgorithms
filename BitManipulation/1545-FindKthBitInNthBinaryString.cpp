/*
    Given two positive integers n and k, the binary string Sn is formed as follows: S1 = "0" Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
    Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1
    changes to 0). For example, the first four strings in the above sequence are:
    S1 = "0"
    S2 = "011"
    S3 = "0111001"
    S4 = "011100110110001"
    Return the kth bit in Sn. It is guaranteed that k is valid for the given n.

    Example 1:
    Input: n = 3, k = 1
    Output: "0"
    Explanation: S3 is "0111001".
    The 1st bit is "0".
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string invert(string& x) {
        for(int i=0; i<x.size(); i++) {
            if(x[i] == '0')
                x[i] = '1';
            else
                x[i] = '0';
        }

        return x;
    }

    char findKthBit(int n, int k) {
        if(n == 1)
            return '0';

        string s = "0";
        for(int i=2; i<=n; i++) {
            string prev = s;
            s += "1";

            string next = invert(prev);
            reverse(next.begin(), next.end());

            s += next;
        }
        
        return s[k-1];
    }
};