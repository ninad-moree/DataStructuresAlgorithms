/*
    Given two binary strings a and b, return their sum as a binary string.

    Example 1:
    Input: a = "11", b = "1"
    Output: "100"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        if(b.size() > a.size()) 
            swap(a,b);

        while(b.size() < a.size()) 
            b = "0" +b;

        int carry = 0;
        int i=a.size()-1;
        int j=b.size()-1;
        
        while(i>=0 && j>=0) {
            if(a[i]=='1' && b[i]=='1') {
                if(carry == 1) 
                    s.push_back('1');
                else {
                    carry = 1;
                    s.push_back('0');
                }
            }
            else if(a[i]=='0' && b[i]=='1' || a[i]=='1' && b[i]=='0') {
                if(carry == 1) {
                    s.push_back('0');
                    carry = 1;
                }
                else 
                    s.push_back('1');
            }
            else {
                if(carry ==1) {
                    s.push_back('1');
                    carry = 0;
                }
                else 
                    s.push_back('0');
            }
            i--;
            j--;
        }
        if(carry == 1) 
            s.push_back('1');

        reverse(s.begin(), s.end());
        return s;
    }
};